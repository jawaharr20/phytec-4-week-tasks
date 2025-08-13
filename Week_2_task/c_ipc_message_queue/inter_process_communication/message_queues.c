#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key = ftok("mqfile", 65);  // Ensure this file exists
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msgbuf message;

    message.mtype = 1;
    strcpy(message.mtext, "Hello via MQ!");

    msgsnd(msgid, &message, sizeof(message.mtext), 0);
    printf("Message sent: %s\n", message.mtext);

    msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);
    printf("Message received: %s\n", message.mtext);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

