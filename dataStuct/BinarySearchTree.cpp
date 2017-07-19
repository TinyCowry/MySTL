/*
二叉搜索树 
http://www.cnblogs.com/skywang12345/p/3576373.html
*/
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
        BSTTree();
        ~BSTTree();

        //遍历
        void preOrder();
        void inOrder();
        void postOrder();

        TreeNode<class T>* search(T x);//递归搜索
        TreeNode<class T>* iteraorsearch(T x);//非递归搜索

        //  最大值和最小值
        T minimum();
        T maximum();

        TreeNode<class T>* successor(TreeNode<class T>* node);//后继节点
        TreeNode<class T>* predecessor(TreeNode<class T>* node);//前驱节点

        void insert(T x);

        void remove(T x);

        void destroy();

        void print();

    private:
        void preOrder(TreeNode<class T>* root);
        void inOrder(TreeNode<class T>* root);
        void postOrder(TreeNode<class T>* root);




        

};
