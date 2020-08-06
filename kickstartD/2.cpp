#include<bits/stdc++.h>
using namespace std;
int sol(vector<int>&arr,int n)
{
    int max_=INT_MIN;
    int count=0;
    for(int i=0;i<n;i++)
    {
        
        if(arr[i]>max_&&(i==n-1||arr[i]>arr[i+1]))
        {
     count++;
        }
        max_=max(max_,arr[i]);


    }
    return count;
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
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int val;
        cin>>val;
        arr.push_back(val);

        }
        int ans=sol(arr,n);
        cout<<"Case "<<"#"<<p+1<<":"<<ans<<endl;
    
    }
}