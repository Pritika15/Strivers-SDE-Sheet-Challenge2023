//Find Duplicate in Array
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int ans;
	vector<int>vis(n,0);
	for(int i=0;i<n;i++)
	{
		if(!vis[arr[i]])
		{
			vis[arr[i]]=1;
		}
		else if(vis[arr[i]]) 
		{
			ans=arr[i];
			break;
		}
	}
	return ans;
}

