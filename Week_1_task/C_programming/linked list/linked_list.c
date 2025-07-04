#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;               // Data part of the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    // Assign data to the node
    newNode->data = data;
    // Initially, set next pointer to NULL
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = createNode(data);

    // If the list is empty, new node becomes the first node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
}

// Function to print the entire linked list
void printList(struct Node* head) {
    struct Node* temp = head;

    // Traverse and print each node's data
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    // Print NULL to indicate end of list
    printf("NULL\n");
}

// Main function to test the linked list
int main() {
    // Initialize an empty list
    struct Node* head = NULL;

    // Insert elements into the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Print the list
    printf("Linked List: ");
    printList(head);

    return 0;
}

