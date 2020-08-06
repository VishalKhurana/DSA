#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,vector<int>>m;
    int n=100000;
    int k=5;
    for(int i=0;i<n;i++)
    {
        vector<int>arr(k);
        m[i]=arr;
        
    }
    cout<<m[55][2]<<endl;

    return 0;
}