#include<bits/stdc++.h>
using namespace std ;
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
        int sum=0;
        bool flag=false;
        if(n%3==0)
        {
            flag=true;
        }
        int condition=flag?0:n%3;
        for(int i=arr.size()-1;i>=condition;i--)
        {
            sum=sum+arr[i-2];
            i=i-2;
        }
        cout<<sum<<endl;
    }
}