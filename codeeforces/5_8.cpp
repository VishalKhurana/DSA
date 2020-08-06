#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
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
        sort(arr.begin(),arr.end());

    
    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
        if(abs(arr[i]-arr[i+1])>1)
        {
            flag=true;
            cout<<"NO"<<endl;
            break;
        }
    }
    if(!flag)
    {
    cout<<"YES"<<endl;
    }
    }

}