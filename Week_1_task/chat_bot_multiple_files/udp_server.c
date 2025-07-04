// udp_server.c

#include <stdio.h>              // For printf(), perror(), fgets()
#include <stdlib.h>             // For exit(), EXIT_FAILURE
#include <string.h>             // For memset(), strlen()
#include <unistd.h>             // For close()
#include <arpa/inet.h>          // For socket programming (struct sockaddr_in, htons, etc.)

#include "common.h"             // Contains shared definitions (like PORT, MAX_BUFFER_SIZE)

// Entry point
int main() {
    int sockfd;                             // Socket file descriptor
    char buffer[MAX_BUFFER_SIZE];          // To store incoming message
    char reply[MAX_BUFFER_SIZE];           // To store reply to send

    struct sockaddr_in servaddr, cliaddr;  // Server and client address structures
    socklen_t len = sizeof(cliaddr);       // Length of client address struct

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Clear server address memory and configure it
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;             // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;     // Accept from any IP
    servaddr.sin_port = htons(PORT);           // Set port (from common.h)

    // Bind the socket to the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("🟢 Server online. Waiting for client...\n");

    // Loop forever to receive and respond to messages
    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);  // Clear buffer before receiving

        // Receive message from client
        recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, 
                 (struct sockaddr *)&cliaddr, &len);
        printf("Client: %s\n", buffer);

        // Ask server user to enter reply
        printf("You (server): ");
        fgets(reply, MAX_BUFFER_SIZE, stdin);  // Read reply from user input

        // Remove newline character if present
        reply[strcspn(reply, "\n")] = 0;

        // Send reply back to client
        sendto(sockfd, reply, strlen(reply), 0, 
               (const struct sockaddr *)&cliaddr, len);
    }

    // Close the socket (not reachable due to infinite loop)
    close(sockfd);
    return 0;
}

