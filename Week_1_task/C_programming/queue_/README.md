# Queue Implementation in C

What is a Queue?

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. This means that the first element added to the queue will be the first one to be removed. You can visualize a queue like a line of people waiting for a service: the first person in line is served first.

Key operations of a queue:

    Enqueue: Add an element to the end of the queue.
    Dequeue: Remove an element from the front of the queue.
    Display: Show all elements in the queue.

About This Project

This project demonstrates a simple implementation of a queue using an array in C.
Main Features

    Fixed-size array-based queue (size = 5)
    Functions for enqueue, dequeue, and display operations
    Simple main function demonstrating usage

How to Compile and Run

    Navigate to the project directory:
    sh

cd Week_1_task/C_programming/queue_

Compile the code:
sh

            gcc queue.c -o queue

Run the executable:
sh

            ./queue

Logic and Explanation

    The queue uses an array of fixed size (5 elements).
    Two pointers, front and rear, keep track of where elements are added and removed.
    When you enqueue, you add a value to the end (rear).
    When you dequeue, you remove a value from the front (front).
    The code checks for “Queue is full” or “Queue is empty” conditions before performing the operations.
    The display function prints the current elements in the queue.

Example Output
Code

Inserted: 10
Inserted: 20
Inserted: 30
Queue: 10 20 30 
Deleted: 10
Queue: 20 30 
Inserted: 40
Queue: 20 30 40 

