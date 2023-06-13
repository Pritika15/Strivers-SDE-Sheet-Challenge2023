//DFS Traversal
void solve(int idx,vector<int>&vis,vector<int>&v,vector<int>adjList[])
{
    vis[idx]=1;
    v.push_back(idx);
    for(auto itr:adjList[idx])
    {
      if (!vis[itr]) {
        solve(itr, vis, v, adjList);
      }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    vector<int>adjList[V];
    for(int i=0;i<edges.size();i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int>vis(V,0);
    for(int i=0;i<V;i++)
    {
        
        if(!vis[i])
        {
            vector<int>v;
            solve(i,vis,v,adjList);
            ans.push_back(v);

        }
       
        //v.clear();
    }
    return ans;
}
