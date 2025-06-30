#include <stdio.h>
#include <string.h>
#include "state_machine.h"

void initStateMachine(StateMachine* sm, void (*callback)(const char*, void*)) {
    sm->currentState = IDLE;
    sm->onEvent = callback;
}

void processEvent(StateMachine* sm, const char* event, void* context) {
    switch (sm->currentState) {
        case IDLE:
            if (strcmp(event, "send") == 0) {
                sm->currentState = SENDING;
                sm->onEvent("Sending message", context);
            } else if (strcmp(event, "receive") == 0) {
                sm->currentState = RECEIVING;
                sm->onEvent("Receiving message", context);
            }
            break;
        case SENDING:
            sm->currentState = IDLE;
            sm->onEvent("Message sent, back to idle", context);
            break;
        case RECEIVING:
            sm->currentState = IDLE;
            sm->onEvent("Message received, back to idle", context);
            break;
    }
}
