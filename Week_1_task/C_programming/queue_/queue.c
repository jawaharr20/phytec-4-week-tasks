#include <stdio.h>

// Define the maximum size of the queue
#define SIZE 5

// Queue array and front/rear pointers
int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int value) {
    // Check if the queue is full
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }

    // If inserting the first element
    if (front == -1) front = 0;

    // Move rear and insert value
    rear++;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    // Check if the queue is empty
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }

    // Print and remove the front element
    printf("Deleted: %d\n", queue[front]);
    front++;
}

// Function to display all elements in the queue
void display() {
    // Check if the queue is empty
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }

    // Print queue elements from front to rear
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    enqueue(10);      // Insert 10
    enqueue(20);      // Insert 20
    enqueue(30);      // Insert 30

    display();        // Output: 10 20 30

    dequeue();        // Remove 10
    display();        // Output: 20 30

    enqueue(40);      // Insert 40
    display();        // Output: 20 30 40

    return 0;
}

