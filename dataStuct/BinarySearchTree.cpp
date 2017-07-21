/*
 *二叉搜索树 
 *http://www.cnblogs.com/skywang12345/p/3576373.html
*/
#ifndef _BINARYSEARCHTREE_
#define _BINARYSEARCHTREE_
#include <iostream>
using namespace std;

template<class T>
struct TreeNode{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(T val, TreeNode* left, TreeNode* right, TreeNode* parent) : 
        val(value), left(l), right(r), parent() {}
}

template<class T>
class BinarySearchTree{
    public:
        BSTree();
        ~BSTree();

        //遍历
        void preOrder();
        void inOrder();
        void postOrder();

        TreeNode<T>* search(T x);//递归搜索
        TreeNode<T>* iteraorsearch(T x);//非递归搜索

        //  最大值和最小值
        T minimum();//返回最小值，为T类型
        T maximum();//返回最大值，为T类型

        TreeNode<class T>* successor(TreeNode<T>* node);//后继节点是该节点的右子树中的最小节点
        TreeNode<class T>* predecessor(TreeNode<T>* node);//前驱节点是该节点的左子树中的最大节点

        void insert(T x);

        void remove(T x);

        void destroy();

        void print();

    private:
        //三种遍历方式
        void preOrder(TreeNode<T>* root) const;
        void inOrder(TreeNode<T>* root) const;
        void postOrder(TreeNode<T>* root) const;

        TreeNode<T>*  search(TreeNode<T>* x, T key);//递归方式
        TreeNode<T>* iteraorsearch(TreeNode<T>* x, T key);//非递归方式

        TreeNode<T>* minimum(TreeNode<T>* node);//二叉树中的最小值，此处返回的是最小点的指针
        TreeNode<T>* maximum(TreeNode<T>* node);//二叉树中的最大值，此处返回的是最大点的指针

        void insert(TreeNode<T>* node, TreeNode<T>* x);//插入
        TreeNode<T>* remove(TreeNode<T>* root, TreeNode<T>* x);//移除

        void destroy(TreeNode<T>* root);//销毁二叉树

        void print(TreeNode<T>* root);//打印二叉树

    private:
        TreeNode<T>* m_root;

};

template<class T>
void BSTree<T>::preOrder(TreeNode<class T>* root) const
{
    if(root != NULL)
    {
        cout << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
}

template<class T>
void BSTree<T>::preOrder()
{
    preOrder(m_root);
}

template<class T>
void BSTree<T>::inOrder(TreeNode<class T>* root) const
{
    if(root != NULL)
    {   
        inOrder(root->left);
        cout << root->val;
        inOrder(root->right);
    }
}

template<class T>
void BSTree<T>::inOrder()
{
    inOrder(m_root);
}

template<class T>
void BSTree<T>::postOrder(TreeNode<class T>* root) const
{
    if(root != NULL)
    {   
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val;
    }
}

template<class T>
void BSTree<T>::postOrder()
{
    postOrder(m_root);
}

template<class T>
TreeNode<T>* BSTree<T>::search(TreeNode<class T>* node, T key)
{
    bool findFlag = false;
    while((!findFlag) || node == NULL)
    {
        if(node->val == key)
            findFlag = true;
        else if(key < node->val)
        {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    template<class T>
TreeNode<T>* BSTree<T>::search(T key)
{
    return search(m_root, key);
}

template<class T>
TreeNode<T>* BSTree<T>::minimum(TreeNode<T>* node)
{
    if(node == NULL)
        return NULL;

    while(node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

template<class T>
T BSTree<T>::minimum()
{
    BSTree<T>* node = minimum(m_root);
    if(node != NULL)
        return node->val;
    else return (T)NULL;
}

template<class T>
TreeNode<T>* BSTree<T>::maximum(TreeNode<T>* node)
{
    if(node == NULL)
        return NULL;

    while(node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

template<class T>
T BSTree<T>::maximum()
{
    BSTree<T>* node = maximum(m_root);
    if(node != NULL)
        return node->val;
    else return (T)NULL;
}

template<class T>
TreeNode<T>* BSTree<T>::successor(TreeNode<T>* node)
{
    if(node->right != NULL)
        return minimum(node->right);//寻找以右孩子为树的最小节点
    
    //如果没有右孩子两种情况
    //1.是左孩子，则后继是父节点
    //2.是右孩子，最低的父节点，且父节点有左孩子
    TreeNode<T>* p = node->parent;
    while(p != NULL && p->right == node)
    {
        node = p;
        p = p->parent;
    }
    return p;
}

template<class T>
TreeNode<T>* BSTree<T>::predecessor(TreeNode* node)
{
    if(node->left != NULL)
        return maximum(node->left);//寻找以左孩子为树的最大节点
    
    //如果没有左孩子两种情况
    //1.是右孩子，则后继是父节点
    //2.是左孩子，最低的父节点，且父节点有右孩子
    TreeNode<T>* p = node->parent;
    while(p != NULL && p->right == node)
    {
        node = p;
        p = p->parent;
    }
    return p;
}

template<class T>
void insert(TreeNode<T>* node, TreeNode<T>* x)
{
    TreeNode<T>* p = NULL;
    while(node != NULL)
    {
        p = node;
        if(x->val < node->val)
            node = node->left;
        else node = node->right;//此处允许插入重复的节点
    }

    x->parent = p;//确定父节点
    if(p == NULL)//根节点为空则将插入的节点作为根节点
        m_root = x;
    if(x->val < p->val)//如果小于父节点则作为父节点的左孩子
        p->left = x;
    else p->right = x;//如果大于父节点则作为父节点的右孩子
}

template<class T>
void insert(T x)
{
    //先创造一个值为x的节点指针
    TreeNode<T>* node = new TreeNode<T>{x, NULL, NULL, NULL};
    insert(m_root, node);
}

template<class T>
void remove(T x)
{
    TreeNode<T>* p = search(T);
    if(p != NULL)
        cout << "该元素不存在" << x << endl;

    
        delete q;
}

template<class T> 
TreeNode<T>* remove(TreeNode<T>* root, TreeNode<T>* p)
{
    if(p->left == NULL && p->right == NULL)//为单叶子节点
        if(p->parent == NULL)//为根节点
        else //不是根节点
            if(p->parent->left == p)
                p->parent->left = NULL;
            else p->parent->right = NULL;

    else if(p->left == NULL || p->right == NULL)//为单支子树
        if(p == m_root)//为根节点，将子树作为根节点
            if(p->left == NULL)
                m_root = p->right;
            else m_root = p->left;
        else //不是根节点，将子树连到父节点上
            if(p->left == NULL)
                p->right->parent = p->parent;
            else p->left->parent = p->parent;
    else //左右子树都不为空，将后继移到该位置
        TreeNode<T>* q = successor(p);//后继左子树必为空
        if(q->right != NULL) //右子树不为空
            q->right->parent = q->parent;//将右子树的父节点连到后继的父节点
        p->val = q->val;
}
#endif //_BINARYSEARCHTREE_