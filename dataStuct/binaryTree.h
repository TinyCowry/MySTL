#ifndef binaryTree_
#define binaryTree_

#include <functional> // for what

using namespace std;

template <class T> // 此处的T是一个节点
class binaryTree{
    public:
        virtual ~binaryTree() {} 
                    //析构函数要是虚函数,要不然自动生成的析构函数不是虚函数
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual void preOrder(void (*) (T *)) = 0;
        virtual void inOrder(void (*) (T *)) = 0;
        virtual void postOrder(void (*) (T *)) = 0;
        virtual void levelOrder(void (*) (T *)) = 0;    
}

