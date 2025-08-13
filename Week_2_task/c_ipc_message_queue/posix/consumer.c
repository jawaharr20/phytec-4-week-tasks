#include <stdio.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>
#include "shared_mq.h"

int main() {
    mqd_t mq;
    char buffer[MAX_MSG_SIZE];

    mq = mq_open(MQ_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    for (int i = 1; i <= 5; i++) {
        ssize_t bytes_read = mq_receive(mq, buffer, MAX_MSG_SIZE, NULL);
        if (bytes_read >= 0) {
            buffer[bytes_read] = '\0';
            printf("Consumed: %s\n", buffer);
        } else {
            perror("mq_receive");
        }
    }

    mq_close(mq);
    mq_unlink(MQ_NAME);  // cleanup
    return 0;
}

