//Tree Traversals
#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    vector<int>Preorder;
    vector<int>Inorder;
    vector<int>Postorder;
    stack<pair<BinaryTreeNode<int> *,int>>s;
    s.push({root,1});
    while(!s.empty())
    {
        BinaryTreeNode<int> *node=s.top().first;
        int val=s.top().second;
        s.pop();
        if(val==1)
        {
            Preorder.push_back(node->data);
            s.push({node,val+1});
            if(node->left) s.push({node->left,1});
        }
        else if(val==2)
        {
            Inorder.push_back(node->data);
            s.push({node,val+1});
            if(node->right) s.push({node->right,1});
        }
        else
        {
            Postorder.push_back(node->data);
        }

    }
    ans.push_back(Inorder);
    ans.push_back(Preorder);
    ans.push_back(Postorder);
    return ans;
}
