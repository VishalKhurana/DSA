#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        long long int l,r,m;
        cin>>l>>r>>m;
        long long int s=l,e=r;
        while(s<=e)
        {
            if(s>=e-m)
            {
                break;
            }
            e--;
            s++;
        }
        cout<<l<<" "<<e<<" "<<s<<endl;
    }
    return 0;
}