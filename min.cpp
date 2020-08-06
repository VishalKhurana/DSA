#include<bits/stdc++.h>
using namespace std;
int sol(vector<int>&entry,vector<int>&exit,int n)
{
    int res=0;
    int max_=INT_MIN;
    for(int i=0;i<n;i++)
    {
        res=res+entry[i]-exit[i];
        max_=max(max_,res);
    }
    return max_;
}
int main()
{
    // int n;
    // cin>>n;
    // vector<int>entry;
    // vector<int>exit;
    // for(int i=0;i<n;i++)
    // {
    //     int val;
    //     cin>>val;
    //     entry.push_back(val);
    // }
    // for(int i=0;i<n;i++)
    // {
    //     int val;
    //     cin>>val;
    //     exit.push_back(val);
    // }
    // int ans=sol(entry,exit,n);
    // cout<<ans<<endl;
    string a="live";
    cout<<a.substr(1)<<endl;
    return 0;
}