//Pair Sum
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>>ans;
   unordered_map<int,int>m;
   for(auto ele:arr)
   {
      int cnt=m[s-ele];
      vector<int>v(2);
      if((s-ele)>=ele)
      {
         v[0]=ele;
         v[1]=s-ele;
      }
      else
      {
         v[0]=s-ele;
         v[1]=ele;
      }
            
      while(cnt--)
      {
         ans.push_back(v);
      }
      m[ele]+=1;
   }
   // for(int i=0;i<ans.size();i++)
   // {
   //    vector<int>temp=ans[i];
   //    sort(temp.begin(),temp.end());
   //    ans[i]=temp;
   // }
   sort(ans.begin(),ans.end());
   return ans;
}
