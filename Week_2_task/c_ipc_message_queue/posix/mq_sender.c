#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define QUEUE_NAME  "/pollmq"
#define MAX_SIZE    128

int main() {
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;       // max messages in queue
    attr.mq_msgsize = MAX_SIZE; // max size of one message
    attr.mq_curmsgs = 0;

    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    const char *msg = "Hello from sender!";
    if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
        perror("mq_send");
    } else {
        printf("Message sent: %s\n", msg);
    }

    mq_close(mq);
    return 0;
}

