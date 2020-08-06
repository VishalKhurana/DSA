#include<bits/stdc++.h>
using namespace std;
void calculatedp(vector<int>&arr,vector<vector<int>>&dp,int n)
{
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap==0)
            {
                dp[i][j]=arr[i];
                continue;
            }
            else if(gap==1)
            {
               dp[i][j]= arr[i]-2*arr[j];
            }
            else
            {
                if(j%2==0)
                {
                    dp[i][j]=dp[i][j-1]+(j+1)*arr[j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1]-(j+1)*arr[j];
                }
                
            }
            

        }
    }
}
int main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int>arr={1,3,9,8,2};
    vector<vector<int>>dp(6,vector<int>(6,0));
    calculatedp(arr,dp,5);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}