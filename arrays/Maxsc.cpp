#include<bits/stdc++.h>
using namespace std;
long long int sol(vector<vector<long long int>>&arr,int n)
{
    long long int sum=0;
    long long int res;
    res=arr[0][n-1];
    sum=arr[0][n-1];
    for(int i=1;i<n;i++)
    {
        bool flag=false;
        for(int j=n-1;j>=0;j--)
        {
            if(arr[i][j]>res)
            {
                flag=true;
                sum+=arr[i][j];
                res=arr[i][j];
                break;

            }

        }
        if(flag==false)
        {
            sum=-1;
            return sum;
        }

    }
    return sum;
}
int main()
{
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        vector<vector<long long int>>arr(n,vector<long long int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int val;
                cin>>val;
                arr[i][j]=val;
            }

        }
        long long int ans=sol(arr,n);
        cout<<ans<<endl;
        
    }
}