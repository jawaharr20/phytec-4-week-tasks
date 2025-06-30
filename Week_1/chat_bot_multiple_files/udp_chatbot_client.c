#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "queue.h"
#include "state_machine.h"

#define MAX_BUFFER_SIZE 256

// Callback function for state machine events
void clientCallback(const char* event, void* context) {
    printf("Client State: %s\n", event);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    Queue messageQueue;
    StateMachine sm;

    // Initialize queue and state machine
    initQueue(&messageQueue);
    initStateMachine(&sm, clientCallback);

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    printf("Connected to chatbot server at %s:%d\n", server_ip, server_port);

    // Superloop for continuous operation
    while (1) {
        // Get user input
        printf("You: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        // Send message
        processEvent(&sm, "send", NULL);
        enqueue(&messageQueue, buffer);
        if (sendto(sockfd, buffer, strlen(buffer), 0,
                   (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Send failed");
            continue;
        }

        // Receive response
        struct sockaddr_in from_addr;
        socklen_t from_len = sizeof(from_addr);
        int n = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0,
                         (struct sockaddr*)&from_addr, &from_len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        buffer[n] = '\0';
        enqueue(&messageQueue, buffer);
        processEvent(&sm, "receive", NULL);
        printf("Chatbot: %s\n", buffer);
    }

    // Cleanup
    freeQueue(&messageQueue);
    close(sockfd);
    return 0;
}
