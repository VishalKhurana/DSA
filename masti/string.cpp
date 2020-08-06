#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        string a,b;
        cin>>a>>b;
        map<char,bool>ma;

        for(int i=0;i<b.size();i++)
        {
            ma[b[i]]=true;
        }
        string ans="";
        for(int i=0;i<a.size();i++)
        {
            if(ma.count(a[i])==0)
            {
                ans=ans+a[i];
            }
        }
        cout<<ans<<endl;
    }
}