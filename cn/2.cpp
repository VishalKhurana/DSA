#include<bits/stdc++.h>
using namespace std;
int main(){
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    for( long long int p=0;p<t;p++)
    {
       long long int n;
        cin>>n;
        vector<long long int>arr;
        vector<long long int>dp(n+1,0);
        for(int i=0;i<n;i++)
        {
           long long int val;
            cin>>val;
        arr.push_back(val);
            
        }
        dp[1]=arr[0];
        for( long long int i=2;i<=n;i++)
        {
            // dp[i]=arr[i-1];
            for(long long  int j=i-1;j>=1;j--)
            {
               
                if((arr[i-1]%arr[j-1])==0)
                {
                    dp[i]=dp[j]+arr[i-1];
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        
    }
 // write your code
    return 0;
}