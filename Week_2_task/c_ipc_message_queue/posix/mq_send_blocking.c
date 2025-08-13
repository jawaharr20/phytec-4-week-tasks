#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

#define QUEUE_NAME "/myqueue_blocking"

int main() {
    mqd_t mq;
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 5;
    attr.mq_msgsize = 256;
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    const char *msg = "Hello from blocking sender!";
    if (mq_send(mq, msg, strlen(msg), 0) == -1) {
        perror("mq_send");
    } else {
        printf("📤 Sent: %s\n", msg);
    }

    mq_close(mq);
    return 0;
}

