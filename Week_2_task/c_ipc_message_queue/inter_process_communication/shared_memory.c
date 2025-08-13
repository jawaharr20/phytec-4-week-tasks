#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    char *shm_ptr;
    
    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    strcpy(shm_ptr, "Shared memory rocks!");
    printf("Written to shared memory.\n");

    shmdt(shm_ptr); // Detach
    shmctl(shmid, IPC_RMID, NULL); // Delete
    return 0;
}

