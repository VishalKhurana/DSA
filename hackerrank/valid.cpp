#include<bits/stdc++.h>
using namespace std;
int sol(string s,int d)
{
    int m=0,count=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(m==d)
        {
            //cout<<i<<endl;
            count++;
            m=0;
        }
         if(s[i]=='1')
        {
            m=0;
            continue;
        }
        else
        {
            m++;
        }
        
    }
    if(m==d)
    {
        return count+1;
    }
    return count;
}
int main()
{
    string s;
    cin>>s;
    int d;
    cin>>d;
    int ans=sol(s,d);
    cout<<ans<<endl;
    return 0;
}