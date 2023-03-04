#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define default_size 10000

template<class T>
class Stack {
private :
    int top;
    T elements[default_size];
public:
    Stack() {
        //nothing in the stack
        top = -1;
        for (int i = 0; i < default_size; i++) {
            elements[i] = NULL;
        }
    }

    bool isFull() {
        //Since the result of (top = default_size) condition is either true or false, you can directly return it
        return top == default_size;
    }

    bool isEmpty() {
        //Since the result of (top = -1) condition is either true or false, you can directly return it
        return top == -1;
    }

    void push(T element) {
        top++;
        if (!isFull()) {
            elements[top] = element;
        } else {
            cout << "Stack is full !" << endl;
            //Since we could not able to insert element, we have to decrease top value
            top--;
        }
    }

    void printStack() {
        cout << "Stack elements" << endl;
        for (int i = 0; i < default_size; i++) {
            //Don't print NULL values, (but it also does not print 0 or empty strings)
            if (elements[i] != NULL) {
                cout << setprecision(11) << elements[i] << "  ";
            }
        }
        cout << endl;
    }

    //Return the top value from array without chancing top index
    T top_value() {
        if (top != -1) {
            return elements[top];
        } else {
            cout << "Stack is empty ! " << endl;
            return NULL;
        }
    }

    vector<T> reverseStack(Stack<T> stack)
    {
        Stack<T> newStack;
        vector<T> list;
        while (!stack.isEmpty())
            newStack.push(stack.pop());

        while (!newStack.isEmpty())
            list.push_back(newStack.pop());
        return list;
    }
    //Return the value from top
    T pop() {
        if (!isEmpty()) {
            T top_element = elements[top];
            //Decrease top value to set new top element
            elements[top] = NULL;
            top--;
            return top_element;
        } else {
            cout << "Stack is empty !" << endl;
            /*Since we can not return an integer value (it would be confusing for user to return something like "0"
             Because it can be an element from stack or error value) we have to return NULL*/
            return NULL;
        }
    }
};