#include<bits/stdc++.h>
using namespace std;

int  sol(int idx,int k,int z,map<int,vector<int>>&dp,int K,int Z,int max_,int n,vector<int>&arr,int flag)
{
    if(idx<1||idx>n)
    {
             return 0;
    }
  if(k>K)
    {
        return 0;
    }
    if(dp[idx][z]!=-1)
    {
        return dp[idx][z];
    }
    long long ans=0;
  if(z==Z)
  {
      ans=sol(idx+1,k+1,z,dp,K,Z,max_,n,arr,0)+arr[idx];
  }
  else
  {
      if(flag==0)
      {
          ans=sol(idx+1,k+1,z,dp,K,Z,max_,n,arr,1)+arr[idx];
      }
      else 
      {
          ans=max(sol(idx+1,k+1,z,dp,K,Z,max_,n,arr,1),sol(idx-1,k+1,z+1,dp,K,Z,max_,n,arr,0))+arr[idx];
      }
      
      
  }
  
    dp[idx][z]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n,k,z;
        cin>>n>>k>>z;
        vector<int>arr;
        arr.push_back(INT_MIN);
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        int max_=INT_MIN;
        map<int,vector<int>>dp;
        for(int i=0;i<=n;i++)
        {
            vector<int>arr(6,-1);
            dp[i]=arr;
        }
        int ans=sol(1,0,0,dp,k,z,max_,n,arr,1);
        cout<<ans<<endl;
        dp.clear();

    }
    return 0;

}