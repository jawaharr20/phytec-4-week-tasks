#include <stdio.h>

// Define states of the FSM
typedef enum {
    IDLE,       // System is idle
    SENDING,    // Sending message
    WAIT_ACK,   // Waiting for ACK
    RECEIVING   // Receiving a message
} State;

// Define possible events that trigger state transitions
typedef enum {
    SEND_REQUEST,       // Request to send a message
    MESSAGE_SENT,       // Message has been sent
    ACK_RECEIVED,       // Acknowledgment received
    TIMEOUT,            // Timeout occurred while waiting for ACK
    MESSAGE_RECEIVED,   // Message has been received
    ACK_SENT            // Acknowledgment sent after receiving message
} Event;

// Global variable to hold the current state (starts in IDLE)
State currentState = IDLE;

// Simulated action: sending a message
void sendMessage() {
    printf(" Sending message...\n");
}

// Simulated action: processing a received message
void processMessage() {
    printf(" Processing received message...\n");
}

// Simulated action: starting a timer for ACK
void startAckTimer() {
    printf(" Starting timer...\n");
}

// FSM handler: determines what to do based on the current state and event
void handleEvent(Event e) {
    switch (currentState) {
        case IDLE:
            if (e == SEND_REQUEST) {
                sendMessage();             // Trigger send action
                currentState = SENDING;    // Transition to SENDING
            } else if (e == MESSAGE_RECEIVED) {
                processMessage();          // Trigger receive action
                currentState = RECEIVING;  // Transition to RECEIVING
            }
            break;

        case SENDING:
            if (e == MESSAGE_SENT) {
                startAckTimer();           // Start timer to wait for ACK
                currentState = WAIT_ACK;   // Transition to WAIT_ACK
            }
            break;

        case WAIT_ACK:
            if (e == ACK_RECEIVED || e == TIMEOUT) {
                // Go back to IDLE whether ACK received or timeout
                currentState = IDLE;
            }
            break;

        case RECEIVING:
            if (e == ACK_SENT) {
                currentState = IDLE;       // Done receiving, go back to IDLE
            }
            break;
    }
}

// Main function to test the FSM flow
int main() {
    printf("Initial State: IDLE\n");

    // Simulate a series of events
    handleEvent(SEND_REQUEST);     // IDLE → SENDING
    handleEvent(MESSAGE_SENT);     // SENDING → WAIT_ACK
    handleEvent(ACK_RECEIVED);     // WAIT_ACK → IDLE

    handleEvent(MESSAGE_RECEIVED); // IDLE → RECEIVING
    handleEvent(ACK_SENT);         // RECEIVING → IDLE

    return 0;
}

