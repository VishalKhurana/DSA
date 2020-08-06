#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        long long int l,r;
        cin>>l>>r;
        int sec=2*l;
        if(sec<=r)
        {
            cout<<l<<" "<<sec<<endl;
        }
        else
        {
            cout<<-1<<" "<<-1<<endl;
        }
        


    }
    return 0;

}