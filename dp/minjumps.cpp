#include<iostream>
#include<vector>
#include<climits>
using namespace  std;
int min(int a,int b)
{
    return a<b?a:b;
}
int minJumps(vector<int>&arr,int k)
{
    vector<int>dp(arr.size(),INT_MAX);
    dp[0]=0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<=i+k;j++)
        {
            dp[j]=min(dp[j],dp[i]+abs(arr[i]-arr[j]));
        }
    }
    return dp[arr.size()-1];



}
int main()
{
    vector<int>arr={ 83, 26, 37, 35, 33, 35, 56 };
    int k=3;
    int ans=minJumps(arr,k);
    cout<<ans<<endl;
}