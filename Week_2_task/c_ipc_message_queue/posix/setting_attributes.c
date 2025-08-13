#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <errno.h>

#define QUEUE_NAME "/myqueue_attr"

int main() {
    mqd_t mq;
    struct mq_attr attr;

    // Define custom attributes
    attr.mq_flags = 0;               // Blocking mode
    attr.mq_maxmsg = 5;              // Max messages allowed in queue
    attr.mq_msgsize = 256;           // Max size of each message
    attr.mq_curmsgs = 0;             // Not set by user (read-only)

    // Create the queue with read-write permission and custom attributes
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    printf(" Message queue created with attributes:\n");
    printf(" mq_maxmsg  = %ld\n", attr.mq_maxmsg);
    printf(" mq_msgsize = %ld\n", attr.mq_msgsize);
    printf(" mq_flags   = %ld\n", attr.mq_flags);

    // Close queue
    mq_close(mq);

    return 0;
}

