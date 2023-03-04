
//18070006034 Nuri Can ÖZTÜRK

#include <iostream>

#include <vector>
#include <random>

#define length(arr) ((sizeof((arr))) / sizeof(((arr)[0])))

using namespace std;

#ifndef MIDTERM_TREE_H
#define MIDTERM_TREE_H

template <class T> class BinaryTreeNode
{
public:
    T data;
    int count;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        count = 1;
        left = NULL;
        right = NULL;
    }
};









template <class T> class Tree {
public:
     int counter;
public:
    BinaryTreeNode<T> *root;
    Tree()
    {
        root = NULL;
        counter = 0;

    }


    bool isEmpty()
    {
        return root == NULL;
    }








    // --------------------------------INSERT ITERATIVE AND RECURSIVE--------------------------------

    void insertIterative(T val)
    {
        BinaryTreeNode<T> *node = new BinaryTreeNode<T>(val);

        if (root == NULL)
            root = node;
        else
        {
            BinaryTreeNode<T> *p = root;
            while (true)
            {
                if (node->data < p->data )
                {
                    if (p->left == NULL)
                    {
                        p->left = node;
                        break;
                    }
                    else p = p->left;
                }
                else if (node->data > p->data)
                {
                    if (p->right == NULL)
                    {
                        p->right = node;
                        break;
                    }
                    else p = p->right;
                }
                else {
                    p->count++;
                    break;
                }
            }
        }
    }

    void insertRecursive(T val)
    {
        if (val == "" || val == " ")
            return;
        BinaryTreeNode<T> *node = new BinaryTreeNode<T>(val);
        BinaryTreeNode<T> *p = root;
        counter++;
        insertRecursive(p , node);
    }
    void insertRecursive(BinaryTreeNode<T> *p,BinaryTreeNode<T> *node)
    {
        if (root == NULL)
            root = node;

        else if (node->data < p->data)
        {
            if (p->left == NULL)
            {
                p->left = node;
                return;
            }
            else insertRecursive(p->left , node);
        }
        else if (node->data > p->data)
        {
            if (p->right == NULL)
            {
                p->right = node;
                return;
            }
            else insertRecursive(p->right , node);
        }
        else
        {
            p->count++;
            return;
        }
    }

// --------------------------------INSERT ITERATIVE AND RECURSIVE--------------------------------








// ---------------------DEPTH TRAVEL RECURSIVE---------------------

    void preOrder(BinaryTreeNode<T> *p)
    {
        if (p == NULL)
            return;
        cout<<p->data<<" ";
        preOrder(p->left);
        preOrder(p->right);
    }

    void postOrder(BinaryTreeNode<T> *p)
    {
        if (p == NULL)
            return;
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<" ";
    }

    void inOrder(BinaryTreeNode<T> *p)
    {
        if (p == NULL)
            return;
        inOrder(p->left);
        cout<<p->count<<"\t\t"<<p->data<<endl;
        inOrder(p->right);
    }

// --------------------- DEPTH TRAVEL RECURSIVE---------------------













// ---------------------TRAVEL ITERATIVE---------------------



// ...



// ---------------------TRAVEL ITERATIVE---------------------

















//--------------------------------------------------------------- MY REMOVE OPERATIONS ---------------------------------------------------------------


private:
    // -------- HELPING TOOLS --------
    BinaryTreeNode<T>* findNude(BinaryTreeNode<T>* p , T val)
    {
        if (p->data == val)
            return p;
        if (val < p->data)
            return findNude(p->left , val);
        if (val > p->data)
            return findNude(p->right , val);
    }
    BinaryTreeNode<T>* gett(BinaryTreeNode<T>*p)
    {
        auto current = p;

        while (current->left->left != NULL)
            current = current->left;
        return current;
    }
    BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* p , T val)
    {
        BinaryTreeNode<T> *k = root;
        while (true)
        {
            if (val < p->data)
            {
                k = p;
                p = p->left;

            }
            else if (val > p->data)
            {
                k = p;
                p = p->right;

            }
            if (val == p->data)
                break;
        }

        return k;
    }
    // -------- HELPING TOOLS --------


    //------------------------------------------ ROOT ------------------------------------------
    BinaryTreeNode<T>* deleteRoot(BinaryTreeNode<T>* p , BinaryTreeNode<T>* deletedNode)
    {
        BinaryTreeNode<T> *t = p;
        p = gett(p->right);
        t->data = p->left->data;
        p->left = NULL;
        return p;
    }
    //------------------------------------------ ROOT ------------------------------------------


    //------------------------------------------ NO CHILDREN ------------------------------------------
    BinaryTreeNode<T>* noChild(BinaryTreeNode<T>* p , BinaryTreeNode<T>* deletedNode)
    {
        BinaryTreeNode<T>* parent = getParent(p,deletedNode->data);
        parent->left != NULL && parent->left->data == deletedNode->data ? parent->left = NULL : parent->right = NULL;
        return p;
    }
    //------------------------------------------ NO CHILDREN ------------------------------------------


    //------------------------------------------ 1 CHILDREN ------------------------------------------
    BinaryTreeNode<T>* oneChild(BinaryTreeNode<T> *p , BinaryTreeNode<T>* deletedNode)
    {
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        if (deletedNode->data < p->data)
        {
            left = getParent(p,deletedNode->data);
            if (left != NULL)
            {
                if (left->left->data == deletedNode->data)
                    left->left = deletedNode->left;
                else left->right = deletedNode->right;

                return p;
            }
        }

        else
        {
            right = getParent(p, deletedNode->data);
            if (right != NULL)
            {
                if (right->right->data == deletedNode->data)
                    right->right = deletedNode->right;
                else right->left = deletedNode->left;
                return p;
            }
        }

    }
    //------------------------------------------ 1 CHILDREN ------------------------------------------


    //------------------------------------------ 2 CHILDREN ------------------------------------------
    BinaryTreeNode<T>* twoChild(BinaryTreeNode<T>* p , BinaryTreeNode<T>* deletedNode)
    {
        BinaryTreeNode<T> *leftChild;
        BinaryTreeNode<T> *rightChild;

        if (deletedNode->data < p->data)
        {
            leftChild = getParent(p,deletedNode->data);
            if (leftChild->left->data == deletedNode->data)
            {
                leftChild->left = deletedNode->left;
                leftChild->left->right = deletedNode->right;
                return p;
            }
        }

        else
        {
            rightChild = getParent(p,deletedNode->data);
            if (rightChild->right->data == deletedNode->data)
            {
                rightChild->right = deletedNode->left;
                rightChild->right->right = deletedNode->right;
                return p;
            }
        }
    }
    //------------------------------------------ 2 CHILDREN ------------------------------------------












public:
    // Driver Code
    BinaryTreeNode<T>* removeItem(BinaryTreeNode<T>* p , T val)
    {
            BinaryTreeNode<T>* deletedNode = findNude(p,val);

            if (val == p->data) // Root
                return deleteRoot(p,deletedNode);
            if (deletedNode->right == NULL && deletedNode->left == NULL && deletedNode->data == val) // NO CHILD
                 return noChild(p,deletedNode);
            if ((deletedNode->left != NULL && deletedNode->right == NULL) || (deletedNode->left == NULL && deletedNode->right != NULL)) // ONE CHILD
                return oneChild(p,deletedNode);
            if (deletedNode->right != NULL && deletedNode->left != NULL)
                return twoChild(p,deletedNode); //TWO CHILD

    }




//--------------------------------------------------------------- MY REMOVE OPERATIONS ---------------------------------------------------------------






    //------------------------------------------ GENERAL OPERATIONS  ------------------------------------------

    bool findItem(T data)
    {
        BinaryTreeNode<T> *p = root;
        if (p == NULL)
            return false;
        while (p != NULL)
        {
            if (data < p->data)
                p = p->left;
            if (data > p->data)
                p = p->right;
            if (data == p->data)
                return true;
        }
        return false;
    }

    int getLeafCount(BinaryTreeNode<T> *p)
    {
        if (p == NULL)
            return 0;
        if (p->right == NULL && p->left == NULL)
            return 1;
        else return (getLeaveCount(p->left) + getLeaveCount(p->right));
    }
    int getHeight(BinaryTreeNode<T>* p )
    {
        if (p == NULL)
            return 0;

        else
        {
            int l = getHeight(p->left);
            int r = getHeight(p->right);

            return max(l,r)+1;
        }

    }

};




#endif //MIDTERM_TREE_H
