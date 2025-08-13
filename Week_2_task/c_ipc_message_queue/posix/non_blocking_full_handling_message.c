#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main() {
    mqd_t mq;
    struct mq_attr attr;

    attr.mq_flags = O_NONBLOCK;
    attr.mq_maxmsg = 3;
    attr.mq_msgsize = 128;
    attr.mq_curmsgs = 0;

    mq = mq_open("/my_fullq", O_CREAT | O_WRONLY | O_NONBLOCK, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        return 1;
    }

    char *msg = "Message to send";

    for (int i = 0; i < 5; i++) {
        if (mq_send(mq, msg, strlen(msg)+1, 0) == -1) {
            if (errno == EAGAIN) {
                printf("Queue is full. Retrying in 1s...\n");
                sleep(1);
            } else {
                perror("mq_send");
                break;
            }
        } else {
            printf("Message %d sent!\n", i+1);
        }
    }

    mq_close(mq);
    mq_unlink("/my_fullq");
    return 0;
}

