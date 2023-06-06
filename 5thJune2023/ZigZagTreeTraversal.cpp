//Binary Tree Zigzag Traversal
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    int cnt=0;
    while(!q.empty())
    {
        int n=q.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            BinaryTreeNode<int> *temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(cnt%2!=0)
            {
              
              v.push_back(temp->data);
            }
            else{
                ans.push_back(temp->data);
            }

        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        ans.push_back(v[i]);
        cnt++;
    }
    return ans;
}

