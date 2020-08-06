#include<bits/stdc++.h>
using namespace std;
int sol(vector<int>&arr,int n,int k)
{
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;j++,i++)
        {
            if(gap==0)
            {
                dp[i][j]=arr[i];
                continue;
            }
            else if(gap==1)
            {
                dp[i][j]=arr[i]^arr[j];
                //continue;
            }
            else
            {
                dp[i][j]=dp[i+1][j]^arr[i];
            }
            
        }
    }
    int max_=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=dp[i][j]^k;
            max_=max(max_,dp[i][j]);
            
        }
       // cout<<endl;
    }
    return max_;
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        int k;
        cin>>n;
        cin>>k;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
           }
           int ans=sol(arr,n,k);
           cout<<ans<<endl;

    }
    return 0;
}