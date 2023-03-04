#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template<class T>
class LinkList {
public:
    Node<T> *head;

    LinkList() {
        head = NULL;
    }

    void insertFirst(T val)
    {
        Node<T> *node = new Node<T>(val);
        insertFirst(node);
    }
    void insertFirst(Node<T> *node) {
        if (node != NULL) {
            if (head == NULL) { // if list is empty
                head = node;
            } else {
                node->next = head;
                head = node;
            }
        } else {
            cout << "Error NULL node" << endl;
        }
    }

    void insert(Node<T> *node, T searchData) {
        if (node != NULL) {
            //Stack is empty
            if (head == NULL) {
                head = node;
            } else {
                bool nodeFound = false;
                Node<T> *tempHead = head;
                while (tempHead != NULL) {
                    if (tempHead->data == searchData) {
                        //First set the next pointer, otherwise you will lose next node
                        node->next = tempHead->next;
                        tempHead->next = node;
                        nodeFound = true;
                        break;
                    }
                    tempHead = tempHead->next;
                }
                if (!nodeFound) {
                    cout << "Could not find element" << endl;
                }
            }
        } else {
            cout << "Error NULL node" << endl;
        }
    }

    void insertLast(T val)
    {
        Node<T> *node = new Node<T>(val);
        insertLast(node);
    }
    void insertLast(Node<T> *node) {
        if (node != NULL) {
            //Stack is empty
            if (head == NULL) {
                head = node;
            } else {
                /*If you move head to the next instead of temp variable, you will lose the previous node positions
                 This loop also shows how to search an element */
                Node<T> *tempHead = head;
                while (tempHead->next != NULL) { // move to the last node
                    tempHead = tempHead->next;
                }
                tempHead->next = node; // insert node at the end
            }
        } else {
            cout << "Error NULL node" << endl;
        }
    }

    void deleteElement(T searchData) {
        Node<T> *tempHead = head;
        bool nodeFound = false;
        while (tempHead != NULL) {
            if (tempHead->next != NULL) {
                if (tempHead->next->data == searchData) {
                    tempHead->next = tempHead->next->next;
                    nodeFound = true;
                    break;
                }
            }
            tempHead = tempHead->next;
        }
        if (head->data == searchData) {
            head = head->next;
            nodeFound = true;
        }
        if (!nodeFound) {
            cout << "Could not find element" << endl;
        }
    }

    Node<T> *removeElement(T searchData) {
        Node<T> *tempHead = head;
        Node<T> *searchNode = NULL;
        bool nodeFound = false;
        while (tempHead != NULL) {
            //Check if next element is NULL
            if (tempHead->next != NULL) {
                if ((tempHead->next->data == searchData)) {
                    searchNode = tempHead->next;
                    tempHead->next = tempHead->next->next;
                    nodeFound = true;
                    break;
                }
            }
            tempHead = tempHead->next;
        }
        //If the removed data element belongs to the head
        if ((head->data == searchData)) {
            searchNode = head;
            head = head->next;
            nodeFound = true;
        }
        if (!nodeFound) {
            cout << "Could not find element" << endl;
        }
        return searchNode;
    }

    LinkList<T> LinkListClone( LinkList<T> newList)
    {
        newList.head = NULL;
        for (Node<T> *p = head ; p != NULL ; p = p->next)
            newList.insertLast(p->data);
        return newList;


    }

    Node<T> *removeFirst() {
        Node<T> *searchNode = NULL;
        if (head != NULL) {
            searchNode = head;
            head = head->next;
        } else {
            cout << "Stack is empty " << endl;
        }
        return searchNode;
    }

    Node<T> *removeLast() {
        Node<T> *tempHead = head;
        Node<T> *searchNode = NULL;
        bool nodeFound = false;
        //While list is not empty
        while (tempHead != NULL) {
            //Check if next element is NULL
            if (tempHead->next != NULL) {
                //Check if next element is the last element
                if (tempHead->next->next == NULL) {
                    searchNode = tempHead->next;
                    tempHead->next = tempHead->next->next;
                    nodeFound = true;
                    break;
                }
            }
            tempHead = tempHead->next;
        }
        //Head is the only element and stack is not empty
        if ((!nodeFound) && (head != NULL)) {
            searchNode = head;
            head = head->next;
            nodeFound = true;
        }
        if (!nodeFound) {
            cout << "Could not find element" << endl;
        }
        return searchNode;
    }

    //Element on the tail, returned but did not removed from the linklist
    Node<T> *topElement() {
        Node<T> *tempHead = head;
        Node<T> *topElement = NULL;
        while (tempHead != NULL) {
            if (tempHead->next == NULL) {
                topElement = tempHead;
                break;
            }
            tempHead = tempHead->next;
        }
        return topElement;
    }

    void printStack() {
        //You have to use temp node when you move the head temporarily, otherwise the node position won't be correct
        cout << "Stack Info" << endl;
        Node<T> *tempHead = head;
        while (tempHead != NULL) {
            cout << tempHead->data << "->";
            tempHead = tempHead->next;
        }
        cout << endl;
    }
};
