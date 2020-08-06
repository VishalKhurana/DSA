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
        if(n%2==0)
        {
            cout<<n/2<<endl;
        }
        else
        {
            cout<<(n-1)/2<<endl;
        }
        
    }
}