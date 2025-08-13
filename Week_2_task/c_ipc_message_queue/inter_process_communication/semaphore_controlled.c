#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
    int val;
};

int main() {
    key_t key = ftok("semfile", 75);
    int semid = semget(key, 1, IPC_CREAT | 0666);

    union semun u;
    u.val = 1;
    semctl(semid, 0, SETVAL, u);

    struct sembuf sb = {0, -1, 0}; // wait
    printf("Trying to enter critical section...\n");
    semop(semid, &sb, 1);
    printf("Inside critical section\n");

    sleep(2); // simulate work

    sb.sem_op = 1; // signal
    semop(semid, &sb, 1);
    printf("Exited critical section\n");

    semctl(semid, 0, IPC_RMID); // cleanup
    return 0;
}

