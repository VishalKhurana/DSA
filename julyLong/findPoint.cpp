#include<bits/stdc++.h>
using namespace std;
pair<int,int>sol(vector<long long int>&x,vector<long long int>&y)
{
    int res_x=x[0];
    int res_y=y[0];
    for(int i=1;i<x.size();i++)
    {
        res_x=res_x^x[i];
        res_y=res_y^y[i];
    }
    pair<int,int>ans;
    ans.first=res_x;
    ans.second=res_y;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int size=4*n-1;
        vector<long long int>x;
        vector<long long int>y;
        for(int i=0;i<size;i++)
        {
            long long int valx,valy;
            cin>>valx>>valy;
            x.push_back(valx);
            y.push_back(valy);

        }
        pair<int,int>ans=sol(x,y);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
}