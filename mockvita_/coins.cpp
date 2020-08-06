#include<bits/stdc++.h>
using namespace std;
 static int Log2n(int n) 
    { 
        return (n > 1) ? 1 + Log2n(n / 2) : 0; 
    } 
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int ans= 1+Log2n(n);
        cout<<ans<<endl;
        
    }
}