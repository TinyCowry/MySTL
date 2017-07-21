#ifndef binaryTreeNode_
#define binaryTreeNode_

using namespace std;

template < class T>
struct binaryTreeNode{
    T element;
    binaryTreeNode<T> *leftChild
                      *rightChild;//note how to write
    
    // 三种初始化的方式
    // 默认初始化全部为0
    // 指定值
    // 指定值和两个指针
    binaryTreeNode() {
        leftChild = rightChild = NULL;
    }

    binaryTreeNode(const T& theElement) : element(theElement), 
        leftChild(NULL), rightChild(NULL)
    {}

    binaryTreeNode(const T& theElement, binaryTreeNode* theLeftChild, binaryTreeNode* theRightChild) :
        element(theElement),
        leftChild(theLeftChild),
        rightChild(theRightChild)
    {}

};

#endif