**Linked List Implementation in C**

This directory contains a simple implementation of a singly linked list in C, located at Week_1_task/C_programming/linked list/linked_list.c.
File Overview

    linked_list.c: Demonstrates how to create a linked list, insert nodes at the end, and print the list.

Code Explanation

The code provides a basic linked list implementation with the following components:

Node Structure
 

       struct Node {
       int data;               // Value stored in the node
       struct Node* next;      // Pointer to the next node
       };

    Each node contains an integer and a pointer to the next node.

createNode(int data) in c 

      struct Node* createNode(int data)

        Allocates memory for a new node, sets its data, and initializes its next pointer to NULL.

      insertAtEnd(struct Node head, int data)**
          Adds a new node with the given data at the end of the list.
          If the list is empty, the new node becomes the head.
          Otherwise, traverses to the last node and links the new node.

       printList(struct Node head)*
           Traverses the list from head to end, printing each node’s data followed by an arrow (->).
           Prints NULL at the end to indicate the termination of the list.

    main()
        Initializes an empty list.
        Inserts the values 10, 20, and 30 at the end.
        Prints the resulting list.

Compilation

To compile the code using gcc:
sh

      gcc linked_list.c -o linked_list

Execution

Run the compiled program:
sh

      ./linked_list

Sample Output
Code

     Linked List: 10 -> 20 -> 30 -> NULL
