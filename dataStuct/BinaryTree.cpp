#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}

class BinaryTree{
    
}

// set map 都是有顺序的容器，要提供函数子进行排序 less<> greater<> 

/*
二叉搜索树
*/
//插入操作,使用递归方法
TreeNode insert(TreeNode* root, int x)//返回的是根节点
{
    TreeNode* insertNode = new TreeNode;
    insertNode->val = x;
    insertNode->left = NULL;
    insertNode->right = NULL;

    if(root == NULL) root = insertNode;//若当前的二叉查找树为空，则插入的元素为根节点
    if (root->val > x) root->left = insert(root->left, x);//若插入的元素值小于根节点值，则将元素插入到左子树中
    else root->right = insert(root->right, x);//若插入的元素值不小于根节点值，则将元素插入到右子树中

    return root;
}

//删除操作，先找到元素
bool remove(TreeNode* root, int x)
{
    TreeNode* node = search(root, x);
    if(node == NULL) return false;
    if(node->left == NULL && node->right == NULL)
    {
        node = NULL;
    }
}

//查找操作,返回节点
TreeNode* search(TreeNode* root, int x)
{
    bool findFlag = false;
    while((!findFlag) || root == NULL)
    {
        if(root->val == x)
            findFlag = true;
        else if(x < root->val)
        {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    if(root == NULL)
        cout << "没有找到元素" << x << endl;

        return root;
}
