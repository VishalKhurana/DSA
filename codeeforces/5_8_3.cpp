#include<bits/stdc++.h>
using namespace std;
int dp[51][51];
map<int,int>m;
int sol(int s,int e,vector<int>&arr,int n)
{
    if(s>=e)
    {
        map<int,int>::iterator it;
        int max_base=INT_MIN;
        for(it=m.begin();it!=m.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
          max_base=max(max_base,it->second);
        }
  cout<<endl;
        return max_base;
    }
    if(s==e-1)
    {
        m[arr[s]+arr[e]]++;
        return 1;
    }
    if(dp[s][e]!=-1)
    {
        return dp[s][e];
    }
  int ans1;
 {
    int temp=arr[s]+arr[e];
    m[temp]++;
   ans1=sol(s+1,e-1,arr,n);
   m[temp]--;
 }
   int ans3=sol(s,e-1,arr,n);
     int ans2=sol(s+1,e,arr,n);
     
     

   return dp[s][e]=max(ans1,max(ans2,ans3));

}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        vector<int>arr;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        sort(arr.begin(),arr.end());
        
        int s=0;
        int e=n-1;

        //map<int,int>m;
        m.clear();
      int ans1=sol(0,n-1,arr,n);
      cout<<ans1<<endl;
    //   int ans2;
    //   if(n&1)
    //   {
    //       ans2=sol(temp,n-1);
    //       int ans=max(ans1,ans2);
    //       cout<<ans<<endl;
    //   }
 
      
      
    }
    return 0;
}