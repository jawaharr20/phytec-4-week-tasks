#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "queue.h"
#include "state_machine.h"

#define MAX_BUFFER_SIZE 256

// Callback function for state machine events
void serverCallback(const char* event, void* context) {
    printf("Server State: %s\n", event);
}

// Simple chatbot response logic
void generateResponse(const char* input, char* response, size_t max_len) {
    char* lower_input = strdup(input);
    for (char* p = lower_input; *p; p++) *p = tolower(*p);

    if (strstr(lower_input, "hello") || strstr(lower_input, "hi")) {
        snprintf(response, max_len, "Hi there! How can I help you today?");
    } else if (strstr(lower_input, "how are you")) {
        snprintf(response, max_len, "I'm doing great, thanks for asking! What's on your mind?");
    } else if (strstr(lower_input, "time")) {
        snprintf(response, max_len, "I don't have a clock, but it's always a good time to chat!");
    } else if (strstr(lower_input, "bye")) {
        snprintf(response, max_len, "Goodbye! Come back soon!");
    } else {
        snprintf(response, max_len, "Hmm, not sure how to respond to that. Try saying 'hello' or 'how are you'!");
    }

    free(lower_input);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];
    char response[MAX_BUFFER_SIZE];
    Queue messageQueue;
    StateMachine sm;

    // Initialize queue and state machine
    initQueue(&messageQueue);
    initStateMachine(&sm, serverCallback);

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    // Bind socket
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Chatbot server listening on %s:%d\n", ip, port);

    // Superloop for continuous operation
    while (1) {
        socklen_t client_len = sizeof(client_addr);
        // Receive message
        int n = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0,
                         (struct sockaddr*)&client_addr, &client_len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        buffer[n] = '\0';
        enqueue(&messageQueue, buffer);
        processEvent(&sm, "receive", NULL);

        // Print received message
        printf("Received from %s:%d: %s\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

        // Generate chatbot response
        generateResponse(buffer, response, MAX_BUFFER_SIZE);
        processEvent(&sm, "send", NULL);
        if (sendto(sockfd, response, strlen(response), 0,
                   (struct sockaddr*)&client_addr, client_len) < 0) {
            perror("Send failed");
        }
        printf("Sent response: %s\n", response);
    }

    // Cleanup
    freeQueue(&messageQueue);
    close(sockfd);
    return 0;
}
