// udp_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "common.h"

int main() {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    char reply[MAX_BUFFER_SIZE];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind socket
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("🟢 Server online. Waiting for client...\n");

    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
        printf("Client: %s\n", buffer);

        printf("You (server): ");
        fgets(reply, MAX_BUFFER_SIZE, stdin);
        reply[strcspn(reply, "\n")] = 0;  // Remove newline

        sendto(sockfd, reply, strlen(reply), 0, (const struct sockaddr *)&cliaddr, len);
    }

    close(sockfd);
    return 0;
}

