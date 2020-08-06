#include<bits/stdc++.h>
using namespace std;
int sol(int n,int k,vector<int>&arr)
{
    int loss=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>k)
        {
            loss=loss+arr[i]-k;
        }
    }
    return loss;
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        int ans= sol(n,k,arr);
        cout<<ans<<endl;
    }
    return 0;
}