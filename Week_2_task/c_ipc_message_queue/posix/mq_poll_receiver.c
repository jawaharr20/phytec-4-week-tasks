// mq_poll_receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include <poll.h>
#include <errno.h>
#include <sys/stat.h>

#define MQ_NAME "/pollmq"
#define MAX_SIZE 128

int main() {
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    mqd_t mq = mq_open(MQ_NAME, O_RDONLY | O_CREAT, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    int fd = mq_getattr(mq, &attr);  // Get current queue attributes
    if (fd == -1) {
        perror("mq_getattr");
        exit(EXIT_FAILURE);
    }

    // Workaround: mq descriptor is not pollable directly, but we can use blocking read + timeout
    printf("Waiting for messages...\n");

    char buffer[MAX_SIZE];
    while (1) {
        ssize_t bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
        if (bytes_read >= 0) {
            buffer[bytes_read] = '\0'; // Null-terminate
            printf("Received: %s\n", buffer);
        } else {
            perror("mq_receive");
            break;
        }
    }

    mq_close(mq);
    mq_unlink(MQ_NAME); // Cleanup
    return 0;
}

