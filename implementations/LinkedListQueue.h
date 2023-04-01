#ifndef DATASTRUCTURE_LINKEDLISTQUEUE_H
#define DATASTRUCTURE_LINKEDLISTQUEUE_H

#include "LinkedList.h"

void *enqueue(void *data);
void *dequeue();
void *peek();
void printQueue(void(*printFunc)(void *));
void freeQueue();

typedef struct QUEUE
{
    LinkedList list;
    void *(*enqueue)(void *);
    void *(*dequeue)(void);
    void *(*peek)(void);
    void (*printQueue)(void);
    void (*freeQueue)(void);
} *Queue;

Queue globalQueue;

Queue createQueue()
{
    Queue queue = malloc(sizeof(struct QUEUE));

    queue->list = create();

    queue->enqueue = &enqueue;
    queue->dequeue	= &dequeue;
    queue->peek = &peek;
    queue->freeQueue = &freeQueue;
    queue->printQueue = (void (*)(void)) &printQueue;
    globalQueue = queue;

    return queue;
}


void *enqueue(void *data)
{
    return insertLast(globalQueue->list, data);
}


void *dequeue()
{
    return removeFirst(globalQueue->list);
}


void *peek()
{
    return globalQueue->list->head->data;
}

void printQueue(void(*printFunc)(void *))
{
    print(globalQueue->list,printFunc);
}

void freeQueue()
{
    freeLinkedList(globalQueue->list);
}

#endif //DATASTRUCTURE_LINKEDLISTQUEUE_H
