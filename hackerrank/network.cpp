#include<bits/stdc++.h>
using namespace std;
int sol(int n,int m,vector<vector<int>>&mat)
{
   vector<vector<int>>dp(n,vector<int>(m,0));
   dp[n-1][m-1]=0;
   //int max_=INT_MIN;
   for(int i=m-2;i>=0;i--)
   {
       dp[n-1][i]=max(dp[n-1][i+1],abs(mat[n-1][i]-mat[n-1][i+1]));


   }
    for(int i=n-2;i>=0;i--)
   {
       dp[i][m-1]=max(dp[i+1][m-1],abs(mat[i][m-1]-mat[i+1][m-1]));


   }
   for(int i=n-2;i>=0;i--)
   {
       for(int j=m-2;j>=0;j--)
       {
          int right=max(dp[i][j+1],abs(mat[i][j]-mat[i][j+1]));
          int down=max(dp[i+1][j],abs(mat[i+1][j]-mat[i][j]));
          dp[i][j]=min(right,down); 
       }
   }
   return dp[0][0];


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m,0));
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           int val;
           cin>>val;
           mat[i][j]=val;
       }
   }
    int ans=sol(n,m,mat);
    cout<<ans<<endl;
    return 0;
}