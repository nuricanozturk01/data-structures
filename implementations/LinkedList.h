//
// Created by msi on 1.04.2023.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H



#include <stdio.h>
#include <malloc.h>

typedef struct NODE
{
    void *data;
    struct NODE *next;

} *Node;

typedef struct LINKEDLIST
{
    Node head;
} *LinkedList;

Node createNode(void *data)
{
    Node node = malloc(sizeof(struct NODE));
    node->data = data;
    node->next = NULL;
}
LinkedList create()
{
    LinkedList list = malloc(sizeof(struct LINKEDLIST));

    list->head = malloc(sizeof(struct NODE));

    list->head->data = NULL;
    list->head->next = NULL;
}

void freeLinkedList(LinkedList list)
{
    free(list->head);
    free(list);
}
int isEmpty(LinkedList list)
{
    return list->head == NULL ? -1 : 0;
}
void *insertLast(LinkedList list, void *data)
{
    Node node = createNode(data);

    if (isEmpty(list) == -1)
    {
        list->head = node;
        return 0;
    }
    else
    {
        Node p = list->head;

        for (; p->next != NULL; p = p->next);

        p->next = node;
        return 0;
    }

    return (void *) -1;
}


void *insertFirst(LinkedList list, void *data)
{
    Node node = createNode(data);

    if (isEmpty(list) == -1)
    {
        list->head = node;
        return 0;
    }
    else
    {
        Node p = list->head;

        list->head = node;

        list->head->next = p;

        return 0;

    }

    return (void *) -1;
}

void *insertAt(LinkedList list, int idx, void *data)
{
    if (idx < 0)
    {
        fprintf(stderr, "Enter the valid index!\n");
        return (void *) -1;
    }
    Node addedNode = createNode(data);

    Node node = list->head;

    for (int i = 0; i < idx - 1; ++i)
        node = node->next;

    Node afterNode = node->next;

    node->next = addedNode;

    addedNode->next = afterNode;

    return 0;

}

// TODO: implement insertAt(LinkedList, void*) function

void print(LinkedList list, void(*printFunc)(void *))
{
    Node node = list->head;

    for (; node != NULL; node = node->next)
        printFunc(node->data);
    printf("NULL");
    printf("\n");
}



void *removeFirst(LinkedList list)
{
    if (isEmpty(list))
    {
        fprintf(stderr, "List already empty!\n");
        return (void *) -1;
    }

    Node p = list->head;

    list->head = p->next;

    free(p);

    return 0;
}

void *removeLast(LinkedList list)
{
    if (isEmpty(list))
    {
        fprintf(stderr, "List already empty!\n");
        return (void *) -1;
    }

    if (list->head->next == NULL)
    {
        list->head = NULL;
        return 0;
    }

    Node p = list->head;

    for (; p->next->next != NULL; p = p->next);

    p->next = NULL;
    void *deleted = p->data;
    free(p->next);
    return deleted;
}

void *removeAt(LinkedList list, int idx)
{
    if (isEmpty(list))
    {
        fprintf(stderr, "List already empty!\n");
        return (void *) -1;
    }

    Node p = list->head;

    for (int i = 0; i < idx - 1; ++i)
        p = p->next;

    Node deleted = p->next;

    void *val = deleted->data;

    Node after = p->next->next;

    p->next = after;

    free(deleted);

    return val;
}

// PRINT FUNCTIONS
void printAsString(void *data)
{
    printf("%s -> ", data);
}


void printAsChar(void *data)
{
    printf("%c -> ", data);
}

void printAsInt(void *data)
{
    printf("%d -> ", (int)data);
}

void printAsIntNewLine(void *data)
{
    printf("%d\n", (int)data);
}
void printAsCharNewLine(void *data)
{
    printf("%c\n", data);
}
void printAsStringNewLine(void *data)
{
    printf("%s\n", data);
}

#endif //DATASTRUCTURE_LINKEDLIST_H
