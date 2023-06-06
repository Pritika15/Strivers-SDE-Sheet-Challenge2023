//Boundary Traversal of Binary Tree
#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool leafNode(TreeNode<int>* root)
{
    if(root->left==NULL && root->right==NULL) return true;
    return false;
}
void LeftTraversal(TreeNode<int>* root, vector<int>&ans)
{
    TreeNode<int>* curr=root->left;
    while(curr)
    {
        if(!leafNode(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}
void Preorder(TreeNode<int>* root, vector<int>&ans)
{
  if (leafNode(root)) {
    ans.push_back(root->data);
    return;
  }
    if(root->left) Preorder(root->left,ans);
    if(root->right) Preorder(root->right,ans);
}
void RightTraversal(TreeNode<int>* root,vector<int>&ans)
{
    vector<int>v;
   TreeNode<int>*curr=root->right;
    while(curr)
    {
        if(!leafNode(curr)) v.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
        
    }

    int n = v.size();
    for(int i=n-1;i>=0;i--)
    {
        ans.push_back(v[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(!leafNode(root)) ans.push_back(root->data);
    //LeftTraversal without leaf nodes
    LeftTraversal(root,ans);
    //PreorderTraversal for leaf nodes
    Preorder(root,ans);
    //right traversal reverse order without the leaf nodes
    RightTraversal(root,ans);
    return ans;
}
