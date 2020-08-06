#include<bits/stdc++.h>
using namespace std;
int sol(string&s)
{
    int count=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if((s[i]=='x'&&s[i+1]=='y')||(s[i]=='y'&&s[i+1]=='x'))
        {
            count++;
            i++;
            continue;
        }
        
        

    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        string s;
        cin>>s;
        int ans=sol(s);
        cout<<ans<<endl;
    }
    return 0;
}