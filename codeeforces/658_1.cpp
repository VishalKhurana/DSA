#include<bits/stdc++.h>
using namespace std;
void sol(vector<int>&arr1,vector<int>&arr2,int n,int m)
{
    map<int,bool>m1;
    map<int,bool>m2;
    for(int i=0;i<n;i++)
    {
        m1[arr1[i]]=true;
    }
    for(int i=0;i<m;i++)
    {
        if(m1[arr2[i]])
        {
            cout<<"YES"<<endl;
            cout<<1<<" "<<arr2[i]<<endl;
            return;
        }
    } 
    cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        vector<int>arr1;
        vector<int>arr2;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr1.push_back(val);
        }
          for(int i=0;i<m;i++)
        {
            int val;
            cin>>val;
            arr2.push_back(val);
        }
        sol(arr1,arr2,n,m);
    }
    return 0;
}