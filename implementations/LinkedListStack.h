#ifndef DATASTRUCTURE_LINKEDLISTSTACK_H
#define DATASTRUCTURE_LINKEDLISTSTACK_H

#include "LinkedList.h"


void *push(void *data);
void *pop();
void *peek();
void printStack(void(*printFunc)(void *));

typedef struct STACK
{
    LinkedList list;
    void *(*push)(void *);
    void *(*pop)(void);
    void *(*peek)(void);
    void (*print)(void);
} *Stack;

Stack globalStack;

Stack createStack()
{
    Stack stack = malloc(sizeof(struct STACK));

    stack->list = create();

    stack->push = &push;
    stack->pop	= &pop;
    stack->peek = &peek;
    stack->print = (void (*)(void)) &printStack;
    globalStack = stack;

    return stack;
}

void *push(void *data)
{
    return insertFirst(globalStack->list, data);
}

void *pop()
{
    return removeFirst(globalStack->list);
}

void *peek()
{
    return globalStack->list->head->data;
}

void printStack(void(*printFunc)(void *))
{
    for (Node p = globalStack->list->head; p != NULL; p = p->next)
        printFunc(p->data);

    printf("\n");
}
#endif //DATASTRUCTURE_LINKEDLISTSTACK_H
