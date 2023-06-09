//Check Identical Trees
#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
//If two trees are identical then their traversal would be the same
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 
    if(root1==NULL || root2==NULL)
    return (root1==root2);

    return((root1->data==root2->data)	 &&identicalTrees(root1->left,root2->left)&& identicalTrees(root1->right,root2->right));

}
