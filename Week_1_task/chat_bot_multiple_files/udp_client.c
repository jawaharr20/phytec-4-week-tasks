// udp_client.c

#include <stdio.h>              // For printf(), perror(), fgets()
#include <stdlib.h>             // For exit(), EXIT_FAILURE
#include <string.h>             // For memset(), strlen(), strcspn()
#include <unistd.h>             // For close()
#include <arpa/inet.h>          // For sockaddr_in, inet_addr(), htons()

#include "common.h"             // Shared definitions like PORT, MAX_BUFFER_SIZE, SERVER_IP

int main() {
    int sockfd;                             // Socket file descriptor
    char buffer[MAX_BUFFER_SIZE];          // Message buffer

    struct sockaddr_in servaddr;           // Server address structure
    socklen_t len = sizeof(servaddr);      // Length of the server address struct

    // Create UDP socket (SOCK_DGRAM)
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&servaddr, 0, sizeof(servaddr));        // Clear the struct
    servaddr.sin_family = AF_INET;                 // IPv4
    servaddr.sin_port = htons(PORT);               // Port from common.h
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP); // Server IP as string

    printf("🟡 Client started. Type messages:\n");

    while (1) {
        printf("You: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);     // Read input from user
        buffer[strcspn(buffer, "\n")] = 0;         // Remove newline character

        // Send message to server
        sendto(sockfd, buffer, strlen(buffer), 0, 
               (const struct sockaddr *)&servaddr, len);

        // Clear buffer to receive reply
        memset(buffer, 0, MAX_BUFFER_SIZE);

        // Receive response from server
        recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, 
                 (struct sockaddr *)&servaddr, &len);
        printf("Server: %s\n", buffer);
    }

    // Close the socket (unreachable due to infinite loop)
    close(sockfd);
    return 0;
}

