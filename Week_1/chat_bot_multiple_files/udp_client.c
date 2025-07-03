// udp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "common.h"

int main() {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in servaddr;
    socklen_t len = sizeof(servaddr);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    printf("🟡 Client started. Type messages:\n");

    while (1) {
        printf("You: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline

        sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *)&servaddr, len);

        memset(buffer, 0, MAX_BUFFER_SIZE);
        recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&servaddr, &len);
        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}

