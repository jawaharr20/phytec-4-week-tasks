#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

#define QUEUE_NAME "/myqueue_blocking"
#define MAX_SIZE   256

int main() {
    mqd_t mq;
    char buffer[MAX_SIZE];
    ssize_t bytes_read;

    // Open existing message queue (created by sender)
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    printf("📨 Waiting for a message... (blocking)\n");

    // BLOCKS here until a message is available
    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0'; // Null-terminate
        printf("✅ Received: %s\n", buffer);
    } else {
        perror("mq_receive");
    }

    mq_close(mq);
    return 0;
}

