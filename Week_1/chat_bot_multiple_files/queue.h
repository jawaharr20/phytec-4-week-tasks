#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100
#define MAX_BUFFER_SIZE 256

typedef struct {
    char* items[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q);
int isQueueFull(Queue* q);
int isQueueEmpty(Queue* q);
void enqueue(Queue* q, const char* item);
char* dequeue(Queue* q);
void freeQueue(Queue* q);

#endif
