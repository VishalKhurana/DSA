#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        long long int n;
        cin>>n;
        vector<long long int>arr;
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            long long int val;
            cin>>val;
            arr.push_back(val);
        }
        for(long long int k=1;k<n;k++)
        {
            if(arr[k]==arr[k-1])
            {
                continue;
            }
            sum=sum+abs((arr[k]-arr[k-1]))-1;
            //cout<<sum<<" ";
          
        }
        cout<<sum<<endl;



    }
}