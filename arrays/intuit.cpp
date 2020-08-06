#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<14)
    {
        cout<<-1<<" "<<-1<<" "<<-1<<endl;
    }
    else
    {
        int jocksholts=n/14;
        int inrJiggles=n%14;
        int jiggles=inrJiggles*34;
        cout<<jocksholts<<" "<<jocksholts<<" "<<jiggles<<endl;

    }
    return 0;
    
}