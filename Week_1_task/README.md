overview of this week Topics



➡️1. State Machine
-------------------

A state machine is a model used to design systems that transition between states based on events. In embedded systems, event-driven state machines are common for handling asynchronous inputs (e.g., button presses, sensor data, or messages).


Key Components:---

    States: Represent distinct conditions or phases of the system.
    Events: External or internal occurrences that trigger transitions between states.
    Transitions: Rules that define how the system moves from one state to another based on specific events and optional guard conditions.
    Actions: Operations performed during state entry, state exit, or during a transition.

Events-
Definition: Events are triggers that cause a state machine to evaluate its current state and potentially transition to another state.
Examples: Timer expiration, message receipt, interrupt signals.
Implementation: Events can be represented as enums or structs, often stored in an event queue for processing.

Event-Driven State Machine
An event-driven state machine processes events from a queue, updating its state based on the current state and event type. Below is an example of a state machine for message exchange (e.g., a communication protocol).

sample code:

    typedef enum {
        STATE_IDLE,
        STATE_ACTIVE,
        STATE_ERROR
    } SystemState;

    SystemState currentState = STATE_IDLE;

    void handle_event(EventType event) {
        switch (currentState) {
            case STATE_IDLE:
                if (event == EVENT_START) {
                    currentState = STATE_ACTIVE;
                    // Perform entry actions for STATE_ACTIVE
                }
                break;
            case STATE_ACTIVE:
                if (event == EVENT_STOP) {
                    currentState = STATE_IDLE;
                    // Perform exit actions for STATE_ACTIVE
                } else if (event == EVENT_FAULT) {
                    currentState = STATE_ERROR;
                }
                break;
            case STATE_ERROR:
                // Handle error state
                break;
        }
    }

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

➡️2. RTOS vs. Superloop
------------------------

---Superloop---

Definition: A superloop is a simple, infinite loop that sequentially executes tasks (e.g., polling sensors, updating outputs) in a single-threaded manner.
Characteristics:
Non-preemptive: Tasks run to completion in a fixed order.
Simple: Minimal overhead, easy to implement for small systems.
Limitations: Poor scalability, no task prioritization, potential delays if a task takes too long.
Use Case: Small systems with predictable, simple tasks (e.g., blinking an LED, reading a sensor).

Pros:
Low memory and CPU overhead.
Deterministic for simple applications.

Cons:
Blocking tasks delay others.
Difficult to handle complex timing or concurrency.

---sample code---

#include <stdint.h>
void led_toggle(void) 
{  }
int read_sensor(void)
 { return 42;}
 void process_data(int data)
{}

void main(void) {
    while (1) {
        // Task 1: Toggle LED every iteration
        led_toggle();

        // Task 2: Read sensor and process data
        int sensor_value = read_sensor();
        process_data(sensor_value);

        // Simple delay (simulate timing)
        for (volatile int i = 0; i < 100000; i++); // Blocking delay
    }
}


---RTOS---

Definition: An RTOS manages multiple tasks (threads) with a scheduler that prioritizes and preempts tasks based on timing or priority.

Characteristics:
Preemptive: Higher-priority tasks can interrupt lower-priority ones.
Task-Based: Each task is a separate function with its own stack and context.
Scheduler: Determines which task runs based on priority or time slices.
Use Case: Complex systems requiring concurrent tasks, real-time constraints, or prioritization (e.g., automotive systems, IoT devices).

Pros:
Handles concurrency and prioritization.
Supports real-time deadlines.
Modular and scalable.

Cons:
Higher memory and CPU overhead.
Increased complexity (context switching, synchronization).

---sample code---


#include <stdint.h>

void rtos_create_task(void (*task)(void*), void* params, int priority);
void rtos_delay(int ms);
void rtos_start(void);

void led_toggle(void) { /* Toggle LED */ }
int read_sensor(void) { return 42; /* Simulated sensor value */ }
void process_data(int data) { /* Process sensor data */ }

void led_task(void* params) {
    while (1) {
        led_toggle();
        rtos_delay(500); // Non-blocking delay (500ms)
    }
}

void sensor_task(void* params) {
    while (1) {
        int sensor_value = read_sensor();
        process_data(sensor_value);
        rtos_delay(1000); // Non-blocking delay (1000ms)
    }
}

// Main function
void main(void) {

    rtos_create_task(led_task, NULL, 2); // Higher priority
    rtos_create_task(sensor_task, NULL, 1); // Lower priority


    rtos_start();
}


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
➡️3. Data Structures
---------------------
Data structures are critical for managing events and data in embedded systems. Below are implementations for Queue, Linked List, and Circular Buffer.

---Queue:---

A queue is a FIFO (First-In, First-Out) data structure used to store events or messages.
Use Case: Buffering incoming messages for the state machine.

---Linked List:---

A linked list is a dynamic data structure where each element (node) contains data and a pointer to the next node.
Use Case: Managing a dynamic list of tasks or events.

---Circular Buffer:---

A circular buffer is a fixed-size buffer where the end wraps around to the beginning, ideal for continuous data streams.
Use Case: Buffering streaming data (e.g., UART communication).

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

➡️4. Pointers:---
------------------
Pointers are variables that store memory addresses, widely used in embedded systems for efficiency and flexibility.

Structure Pointers:-
Used to access and manipulate struct members dynamically.
Example: Accessing state machine configuration.


-Function Pointers and Callbacks:-
Function pointers allow dynamic function calls, often used for callbacks in event-driven systems.
Use Case: Registering a callback to handle specific events in the state machine.

Array and Pointers:-
Arrays are often manipulated using pointers for efficient memory access.
Example: Iterating through a buffer using pointer arithmetic.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

➡️5. Bit Operations & Byte Packing
-----------------------------------
Bit Operations: Used for manipulating individual bits (e.g., setting, clearing, toggling flags).
Common operations: & (AND), | (OR), ^ (XOR), ~ (NOT), << (left shift), >> (right shift).
Use Case: Configuring hardware registers or status flags.
Byte Packing: Packing multiple fields into a single byte to save memory, often used in communication protocols.
Example: Packing message type and flags into a single byte.


=======================================================================================================================================================================================================
