
**Circular Buffer Implementation in C**

This project demonstrates a simple implementation of a circular buffer (ring buffer) in C. A circular buffer is a fixed-size data structure that works as a queue, wrapping around to the beginning when it reaches the end.
Features

    Enqueue (add) elements to the buffer.
    Dequeue (remove) elements from the buffer.
    Display buffer contents.
    Handles buffer full and empty conditions.

File

    circular_buffer_implementation.c

How to Compile and Run: 

    gcc circular_buffer_implementation.c -o circular_buffer_implementation

Run the program:
Code

    ./circular_buffer_implementation

Sample Output
Code

     Circular Buffer contents: 10 20 30 
     Dequeued: 10
     Circular Buffer contents: 20 30 

Explanation

    The buffer is initialized with a size of 5.
    Three values (10, 20, and 30) are enqueued.
    The buffer contents are displayed.
    One value is dequeued (10).
    The buffer contents are displayed again.

Functions Overview

    init_buff(cirbuf *cb): Initializes the buffer.
    enqueue(cirbuf *cb, int data): Adds data to the buffer. Prints a message if full.
    dequeue(cirbuf *cb, int *data): Removes data from the buffer. Prints a message if empty.
    display(cirbuf *cb): Displays the contents of the buffer from tail to head.

![image](https://github.com/user-attachments/assets/6a114e8a-966a-4c01-ab33-8926cb9a5c3c)
