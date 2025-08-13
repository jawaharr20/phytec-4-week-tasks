// q12_mq_send.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>

int main() {
    mqd_t mq;
//    const char *queue_name = "/demo_queue";
     const char *queue_name = "/myqueue";  // MUST match mq_create_open

    const char *message = "Hello from mq_send!";

    mq = mq_open(queue_name, O_WRONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        exit(1);
    }

    printf("Message sent: %s\n", message);
    mq_close(mq);
    return 0;
}

