//18070006034 Nuri Can ÖZTÜRK

#include "LinkedList.h"
#include "Tree.h"

#ifndef HW4_WORD_H
#define HW4_WORD_H


class Word {
protected:
    LinkedList<string> list;
    Tree<string> tree;

public:

    void getDistinctWords()
    {
       for (Node<string> *p = list.head ; p != NULL ; p = p->next)
            tree.insertRecursive(p->data);

        InOrderTravels(tree.root);

       // cout<<"Sum Of Word : "<<tree.counter<<endl;
    }

    virtual void InOrderTravels(BinaryTreeNode<string> *p) = 0;

};


#endif //HW4_WORD_H
