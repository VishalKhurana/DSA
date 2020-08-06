#include<bits/stdc++.h>
using namespace std;
int bionomial(int n,int k)
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++)
{
    for(int j=0;j<=min(k,i);j++)
    {
        if(j==0||j==n)
        {
            dp[i][j]=1;

        }
        else if(j==1)
        {
            dp[i][j]=i;
        }
        else
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
        
    }
}
return dp[n][k];


}
int main()
{
    int n;
    cin>>n;

    vector<int>arr;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr.push_back(val);
        sum+=val;
       
    }
    int k;
    cin>>k;

    int bionomial_coeff=bionomial(n,k);
    int ans=(sum*bionomial_coeff*k)/n;
    cout<<ans<<endl;

    //cout<<ans<<endl;
    return 0;

}