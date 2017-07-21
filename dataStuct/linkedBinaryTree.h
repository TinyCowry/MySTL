#ifndef linkedBinaryTree_
#define linkedBinaryTree_

#include <iostream>
#include "binaryTree.h"
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"
#include "booster.h"

using namespace std;

template <class E>
class linkedBinaryTree : public binaryTree<<binaryTreeNode<E> > {
    public:
        linkedBinaryTree() {root = NULL; treeSize = 0;}
        virtual ~linkedBinaryTree(){erase();}

        bool empty() const {return treeSize == 0;}
        int size() const {return treeSize;}
        E* element() cosnt;
        void makeTree(const E& element, linkedBinaryTree<E>&, linkedBinaryTree<E>&);
        linkedBinaryTree<E>& removeLeftSubtree();
        linkedBinaryTree<E>& removeRightSubtree();
        void preOrder(void (*theVisit) binaryTreeNode<E>*){
            visit = theVisit; preOrder(root);
        }
        void inOrder(void(*theVisit)(binaryTreeNode<E>*))
           {visit = theVisit; inOrder(root);}
      void postOrder(void(*theVisit)(binaryTreeNode<E>*))
           {visit = theVisit; postOrder(root);}
      void levelOrder(void(*)(binaryTreeNode<E> *));
}