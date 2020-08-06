#include<bits/stdc++.h>
using namespace std;
int sol(vector<int>&arr,int n)
{
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;j++,i++)
        {
            if(gap==0)
            {
                dp[i][j]=0;
            }
            else if(gap==1)
            {
                dp[i][j]=arr[i]+arr[j];
            }
            else
            {
               dp[i][j]=min(arr[j]+dp[i][j-1],arr[i]+dp[i+1][j]);
            }
            

        }
    }
    int ans=dp[0][n-1];
    for(int i=n-2;i>=0;i--)
    {
        ans=ans+(dp[0][i+1]-dp[0][i]);
        //cout<<ans<<" ";

    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr.push_back(val);

    }
    int ans=sol(arr,n);
    cout<<ans<<endl;
    
    return 0;
}