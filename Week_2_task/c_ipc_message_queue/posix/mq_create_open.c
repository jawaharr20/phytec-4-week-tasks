#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // For O_* constants
#include <sys/stat.h>   // For mode constants
#include <mqueue.h>

int main() {
    const char *queue_name = "/myqueue";  // Must start with /
    
    // Define message queue attributes
    struct mq_attr attr;
    attr.mq_flags = 0;        // Blocking mode
    attr.mq_maxmsg = 10;      // Max messages
    attr.mq_msgsize = 256;    // Max message size
    attr.mq_curmsgs = 0;      // Number of messages currently in queue

    // Open or create message queue
    mqd_t mq = mq_open(queue_name, O_CREAT | O_RDWR, 0666, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    printf("Message queue '%s' created and opened successfully.\n", queue_name);

    // Cleanup: Close queue
    mq_close(mq);

    return 0;
}

