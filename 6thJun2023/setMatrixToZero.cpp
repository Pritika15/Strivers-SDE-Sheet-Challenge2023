//Set Matrix Zeros
#include <bits/stdc++.h>
void RowColtoZero(int i, int j,vector<vector<int>> &matrix,vector<pair<int,int>>&v)
{
	//up
	int k=i-1;
	while(k>=0)
	{
		if(matrix[k][j]!=0)
		{
			v.push_back({k,j});
		}
		k--;
	}
	//left
	int l=j-1;
	while(l>=0)
	{
		if(matrix[i][l]!=0)
		{
			v.push_back({i,l});
		}
		l--;
	}
	//down
	int a=i+1;
	while(a<matrix.size())
	{
		if(matrix[a][j]!=0)
		{
			v.push_back({a,j});
		}
		a++;
	}
	//right
	int r=j+1;
	while(r<matrix[0].size())
	{
		if(matrix[i][r]!=0)
		{
			v.push_back({i,r});
		}
		r++;
	}

}
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	vector<pair<int,int>>v;
	int n=matrix.size();
	int m=matrix[0].size();
	for(int i=n-1;i>=0;i-- )
	{
		for(int j=m-1;j>=0;j--)
		{
			if(matrix[i][j]==0)
			{
				RowColtoZero(i,j,matrix,v);
			}
		}
	}
	for(int i=0;i<v.size();i++)
	{
		int x=v[i].first;
		int y=v[i].second;
		matrix[x][y]=0;
	}
}
