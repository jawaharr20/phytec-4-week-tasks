#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueFull(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

int isQueueEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, const char* item) {
    if (isQueueFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = strdup(item);
    q->size++;
}

char* dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    char* item = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return item;
}

void freeQueue(Queue* q) {
    while (!isQueueEmpty(q)) {
        char* item = dequeue(q);
        free(item);
    }
}
