#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    IDLE,
    SENDING,
    RECEIVING
} State;

typedef struct {
    State currentState;
    void (*onEvent)(const char*, void*);
} StateMachine;

void initStateMachine(StateMachine* sm, void (*callback)(const char*, void*));
void processEvent(StateMachine* sm, const char* event, void* context);

#endif
