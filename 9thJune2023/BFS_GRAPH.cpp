//BFS in Graph
#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>ans;
    vector<int>adjList[vertex];
    for(auto e:edges)
    {
        adjList[e.first].push_back(e.second);
        adjList[e.second].push_back(e.first);
    }
    
    vector<int>vis(vertex,0);
    for(int i=0;i<vertex;i++ )
    {
        if(!vis[i])
        {
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                int curr=q.front();
                q.pop();
                if(vis[curr]) continue;
                vis[curr]=1;
                ans.push_back(curr);
                sort(adjList[curr].begin(),adjList[curr].end());
                for(auto itr: adjList[curr])
                {
                    if(!vis[itr])
                    q.push(itr);
                }
                
                
                
                
            }
        }
    }
    return ans;
}
