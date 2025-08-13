// mq_nonblock_receive.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

int main() {
    mqd_t mq;
    char buffer[256];

    mq = mq_open("/nonblockq", O_RDONLY | O_NONBLOCK);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    ssize_t bytes_read = mq_receive(mq, buffer, sizeof(buffer), NULL);
    if (bytes_read >= 0) {
        printf("Message received: %s\n", buffer);
    } else {
        if (errno == EAGAIN)
            printf("Queue empty, nothing to read.\n");
        else
            perror("mq_receive");
    }

    mq_close(mq);
    return 0;
}

