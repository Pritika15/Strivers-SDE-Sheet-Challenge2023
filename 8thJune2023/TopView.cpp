//Top View Of Binary Tree
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void Preorder(TreeNode<int> *root,vector<pair<int,pair<int,int>>>&vals,int i, int j)
{
    vals.push_back({i,{j,root->val}});
    if(root->left) Preorder(root->left,vals,i-1,j+1);
    if(root->right) Preorder(root->right,vals,i+1,j+1);
}
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int>ans;
    if(!root) return ans;
    vector<pair<int,pair<int,int>>>vals;
    Preorder(root,vals,0,0);
    sort(vals.begin(),vals.end());
    for(int i=0;i<vals.size();i++)
    {
        
       
        if(i!=0 && vals[i-1].first==vals[i].first) continue;
        ans.push_back(vals[i].second.second);
    }
    return ans;
}
