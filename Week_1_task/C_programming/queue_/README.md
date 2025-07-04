**Queue Implementation in C**

This program demonstrates a simple queue data structure using an array in C. It allows enqueue (insertion), dequeue (deletion), and display operations.
File

      queue.c

Compilation
sh

      gcc queue.c -o queue

Running
sh

     ./queue

Description

    The queue has a maximum size of 5.
    Three main operations are provided:
        Enqueue: Insert an element at the rear.
        Dequeue: Remove an element from the front.
        Display: Show all current elements in the queue.

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

