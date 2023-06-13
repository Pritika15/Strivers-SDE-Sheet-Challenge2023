//Diameter Of Binary Tree
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int FindH(TreeNode<int> *root,int &maxi)
{
    if(!root) return 0;
    int leftH=FindH(root->left, maxi);
    int rightH=FindH(root->right, maxi);
    maxi=max(maxi,(leftH+rightH));
    
    return 1+max(leftH,rightH);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(!root) return 0;
    int maxi=0;
    FindH(root,maxi);
    return maxi;
}

