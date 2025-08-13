#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

#define QUEUE_NAME  "/myqueue"

int main() {
    mqd_t mq;
    struct mq_attr attr;
    char *buffer;

    // Open queue for reading
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    // Get queue attributes
    if (mq_getattr(mq, &attr) == -1) {
        perror("mq_getattr");
        exit(1);
    }

    // Allocate buffer based on actual message size
    buffer = malloc(attr.mq_msgsize + 1);
    if (!buffer) {
        perror("malloc");
        exit(1);
    }

    // Receive the message
    ssize_t bytes_read = mq_receive(mq, buffer, attr.mq_msgsize, NULL);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0'; // Null-terminate
        printf("📥 Received: %s\n", buffer);
    } else {
        perror("mq_receive");
    }

    // Cleanup
    free(buffer);
    mq_close(mq);
    return 0;
}

