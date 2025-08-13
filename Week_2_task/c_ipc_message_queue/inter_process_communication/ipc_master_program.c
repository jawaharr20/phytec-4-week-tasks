/*
 * Master Program to Demonstrate All IPC Mechanisms:
 * - Unnamed Pipe
 * - Named Pipe (FIFO)
 * - Shared Memory
 * - Semaphores
 * - System V Message Queues
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/stat.h>

#define SHM_SIZE 1024
#define FIFO_PATH "/tmp/myfifo"
#define MSG_KEY 1234
#define SHM_KEY 5678
#define SEM_KEY 9999

// ---------------- MESSAGE QUEUE STRUCT ----------------
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

// ---------------- SEMAPHORE OPERATIONS ----------------
void sem_op(int semid, int op) {
    struct sembuf sb = {0, op, 0};
    semop(semid, &sb, 1);
}

// ---------------- MAIN ----------------
int main() {
    pid_t pid;
    int pipefd[2];
    char buf[100];

    // 1. UNNAMED PIPE
    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        close(pipefd[0]);
        char msg[] = "Hello from child via pipe!";
        write(pipefd[1], msg, strlen(msg) + 1);
        exit(0);
    } else {
        wait(NULL);
        close(pipefd[1]);
        read(pipefd[0], buf, sizeof(buf));
        printf("[PIPE] Parent received: %s\n", buf);
    }

    // 2. NAMED PIPE (FIFO)
    mkfifo(FIFO_PATH, 0666);
    pid = fork();
    if (pid == 0) {
        int fd = open(FIFO_PATH, O_WRONLY);
        write(fd, "Hi from FIFO!", 14);
        close(fd);
        exit(0);
    } else {
        wait(NULL);
        int fd = open(FIFO_PATH, O_RDONLY);
        read(fd, buf, sizeof(buf));
        printf("[FIFO] Received: %s\n", buf);
        close(fd);
        unlink(FIFO_PATH);
    }

    // 3. SHARED MEMORY
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    char *shm_ptr = (char *)shmat(shmid, NULL, 0);
    pid = fork();
    if (pid == 0) {
        char *shm_child = (char *)shmat(shmid, NULL, 0);
        strcpy(shm_child, "Shared memory message!");
        shmdt(shm_child);
        exit(0);
    } else {
        wait(NULL);
        printf("[SHM] Parent read: %s\n", shm_ptr);
        shmdt(shm_ptr);
        shmctl(shmid, IPC_RMID, NULL);
    }

    // 4. SEMAPHORES + SHM for sync
    int semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 1);
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    shm_ptr = (char *)shmat(shmid, NULL, 0);

    pid = fork();
    if (pid == 0) {
        char *shm_child = (char *)shmat(shmid, NULL, 0);
        sem_op(semid, -1);
        strcpy(shm_child, "Sem synchronized write!");
        sem_op(semid, 1);
        shmdt(shm_child);
        exit(0);
    } else {
        wait(NULL);
        sem_op(semid, -1);
        printf("[SEMAPHORE] Synced read: %s\n", shm_ptr);
        sem_op(semid, 1);
        shmdt(shm_ptr);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID);
    }

    // 5. SYSTEM V MESSAGE QUEUE
    int msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    struct msg_buffer message;
    pid = fork();
    if (pid == 0) {
        message.msg_type = 1;
        strcpy(message.msg_text, "Message via queue!");
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        exit(0);
    } else {
        wait(NULL);
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("[MSGQ] Received: %s\n", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}

