#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define buffer size
#define BUFF_SIZE 5

// Define the circular buffer structure
typedef struct {
    int buff[BUFF_SIZE]; // Array to hold the data
    int head;            // Index where new data will be written
    int tail;            // Index from where data will be read
    int count;           // Number of elements currently in the buffer
} cirbuf;

// Initialize the buffer: set head, tail, and count to 0
void init_buff(cirbuf *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Add (enqueue) data to the circular buffer
bool enqueue(cirbuf *cb, int data) {
    // Check if buffer is full
    if (cb->count == BUFF_SIZE) {
        printf("Buffer is full\n");
        return false;
    }

    // Add data at the head index
    cb->buff[cb->head] = data;

    // Move head forward in circular manner
    cb->head = (cb->head + 1) % BUFF_SIZE;

    // Increase count of elements
    cb->count++;

    return true;
}

// Remove (dequeue) data from the circular buffer
bool dequeue(cirbuf *cb, int *data) {
    // Check if buffer is empty
    if (cb->count == 0) {
        printf("Buffer is empty\n");
        return false;
    }

    // Read data from the tail index
    *data = cb->buff[cb->tail];

    // Move tail forward in circular manner
    cb->tail = (cb->tail + 1) % BUFF_SIZE;

    // Decrease count of elements
    cb->count--;

    return true;
}

// Display the contents of the circular buffer
void display(cirbuf *cb) {
    printf("Circular Buffer contents: ");

    // Print elements from tail to head in order, using circular indexing
    for (int i = 0; i < cb->count; i++) {
        int index = (cb->tail + i) % BUFF_SIZE;
        printf("%d ", cb->buff[index]);
    }

    printf("\n");
}

// Main function to test circular buffer operations
int main() {
    cirbuf cb;

    // Initialize the buffer
    init_buff(&cb);

    // Enqueue some elements
    enqueue(&cb, 10);
    enqueue(&cb, 20);
    enqueue(&cb, 30);

    // Display current buffer
    display(&cb);  // Expected output: 10 20 30

    int value;

    // Dequeue one element
    dequeue(&cb, &value);
    printf("Dequeued: %d\n", value); // Expected: 10

    // Display buffer after dequeue
    display(&cb);  // Expected output: 20 30

    return 0;
}

