#include<bits/stdc++.h>
using namespace std;
int sol(vector<int>&arr,int or_,int n)
{
    vector<vector<int>>count(or_+1,vector<int>(n+1));
    vector<vector<int>>subset(or_+1,vector<int>(n+1));
    for(int i=0;i<=n;i++)
    {
        count[0][i]=0;
        subset[0][i]=true;
        
    }

    for(int i=1;i<=or_;i++)
    {
        count[i][0]=INT_MAX;
        subset[i][0]=false;

    }

    for(int i=1;i<=or_;i++)
    {
        for(int j=1;j<=n;j++)
        {
            subset[i][j]=subset[i][j-1];
            count[i][j]=count[i][j-1];

            if(i>=arr[j-1])
            {
                subset[i][j]=subset[i][j]||subset[i-arr[j-1]][j-1];
                if(subset[i][j])
                {
                    count[i][j]=min(count[i][j-1],count[i-arr[j-1]][j-1]+1);
                }
            }
        }
    }
    return count[or_][n];

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
    int or_=arr[0];
    for(int i=1;i<n;i++)
    {
        or_=or_|arr[i];
    }
    cout<<or_<<endl;
    int ans=sol(arr,or_,n);
    cout<<ans<<endl;
}