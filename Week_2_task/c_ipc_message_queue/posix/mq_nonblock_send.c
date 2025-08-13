// mq_nonblock_send.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

int main() {
    mqd_t mq;
    const char *msg = "Hello from non-blocking sender!";
    struct mq_attr attr = {
        .mq_flags = 0,
        .mq_maxmsg = 5,
        .mq_msgsize = 256,
        .mq_curmsgs = 0
    };

    mq = mq_open("/nonblockq", O_CREAT | O_WRONLY | O_NONBLOCK, 0666, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
        if (errno == EAGAIN)
            printf("Queue full, message not sent.\n");
        else
            perror("mq_send");
    } else {
        printf("Message sent: %s\n", msg);
    }

    mq_close(mq);
    return 0;
}

