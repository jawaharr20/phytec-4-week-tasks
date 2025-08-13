#include <stdio.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "shared_mq.h"

int main() {
    mqd_t mq;
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MSG_COUNT;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    mq_unlink(MQ_NAME); // Clean up any old queue
    mq = mq_open(MQ_NAME, O_CREAT | O_WRONLY, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    char msg[MAX_MSG_SIZE];
    for (int i = 1; i <= 5; i++) {
        snprintf(msg, sizeof(msg), "Message %d", i);
        if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
            perror("mq_send");
        } else {
            printf("Produced: %s\n", msg);
        }
        sleep(1);  // simulate work
    }

    mq_close(mq);
    return 0;
}

