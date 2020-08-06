#include<bits/stdc++.h>
using namespace std;
long long int sol(vector<long long int>&a,vector<long long int>&b,int n,long long int &min_a,long long int &min_b)
{

    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        long long int diff_a=a[i]-min_a;
        long long int diff_b=b[i]-min_b;

        sum=sum+(min(diff_a,diff_b)+(max(diff_a,diff_b)-min(diff_a,diff_b)));
        

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
        vector<long long int>a;
        vector<long long int>b;
            long long int min_a=INT_MAX;
            long long int min_b=INT_MAX;

        for(int i=0;i<n;i++)
        {
            long long int val;
            cin>>val;
            min_a=min(min_a,val);
            a.push_back(val);
        }
         for(int i=0;i<n;i++)
        {
            long long int val;
            cin>>val;
            min_b=min(min_b,val);
            b.push_back(val);
        }
        long long int ans=sol(a,b,n,min_a,min_b);
        cout<<ans<<endl;
    }
    return 0;
}