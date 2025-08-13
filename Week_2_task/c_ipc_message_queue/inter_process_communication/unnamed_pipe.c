#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char msg[] = "Hello from parent";
    char buf[100];

    pipe(fd);
    pid = fork();

    if (pid == 0) {
        // Child
        close(fd[1]);  // Close write end
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(fd[0]);
    } else {
        // Parent
        close(fd[0]);  // Close read end
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
    }
    return 0;
}

