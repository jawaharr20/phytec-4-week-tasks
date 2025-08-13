// File: mq_delete.c
#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>

int main() {
    const char *queue_name = "/my_nonblock_queue";

    // Delete the queue
    if (mq_unlink(queue_name) == -1) {
        perror("mq_unlink");
        exit(EXIT_FAILURE);
    }

    printf("Message queue '%s' deleted successfully.\n", queue_name);
    return 0;
}

