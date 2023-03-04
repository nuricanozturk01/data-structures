//18070006034 Nuri Can ÖZTÜRK
#include <iostream>
using namespace std;

#ifndef MIDTERM_LINKEDLIST_H
#define MIDTERM_LINKEDLIST_H

template <class T> class Node
{
public:
    T data;
    Node<T>* next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }

};
template <class T> class LinkedList {
public:
    Node<T>* head;

    LinkedList()
    {
        head = NULL;
    }


    bool isEmpty(){return head == NULL;}

    void insertFirst(T data)
    {
        Node<T> *node = new Node<T>(data);

        if (isEmpty())
            head = node;
        else
        {
            node->next = head;
            head = node;
        }
    }

    void insertLast(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (isEmpty())
            head = node;
        else
        {
            Node<T>*p = head;
            for ( ; p->next != NULL ; p = p->next);
            p->next = node;
        }

    }

    void insertAfterIndex(T data , int index)
    {
        Node<T> *node = new Node<T>(data);
        if (isEmpty() || index == 0)
            head = node;

        else
        {
            Node<T>* p = head;
            for (int i = 0 ; i < index - 1 ; ++i)
                p = p->next;
            node->next = p->next;
            p->next = node;
        }
    }

    T deleteFirst()
    {
        if (isEmpty())
            return NULL;
        if (head->next == NULL)
            return NULL;
        else
        {
            Node<T>* del = head;
            head = head->next;
            return del->data;
        }

    }

    T deleteLast()
    {
        if (isEmpty())
            return NULL;

        Node<T> *p = head;

        for ( ; p->next->next != NULL ; p = p->next);
        T val = p->next->data;
        p->next = NULL;
        return val;

    }

    void deleteIndex(int index)
    {
        if (index == 0 || head == NULL)
            return ;
        else
        {
            Node<T> *p = head;
            for (int i = 0 ; i < index - 2 ; p = p->next , ++i);
            p->next = p->next->next;
        }
    }
    void print()
    {
        for (Node<T>*p = head ; p != NULL ; p = p->next)
            cout<<"\""<<p->data<<"\""<<endl;

    }

};


#endif //MIDTERM_LINKEDLIST_H
