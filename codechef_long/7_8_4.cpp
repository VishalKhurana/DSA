#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int pp=0;pp<t;pp++)
    {
        string s,p;
        cin>>s>>p;
        map<char,int>ms,mp;
        char last='5';
        for(int i=0;i<s.size();i++)
        {
            ms[s[i]]++;
        }
        for(int i=0;i<p.size();i++)
        {
            mp[p[i]]++;
            ms[p[i]]--;
            
        }
        char front=p[0];
        //cout<<ms['a']<<endl;
        char c='a';
       
        string ans="";
        while(c!=front)
        {
            int size=ms[c];
            for(int i=0;i<size;i++)
            {
            ans=ans+c;
            ms[c]--;
            }
            c++;


        }
        
        int si=ms[c];
        if(p.size()>1)
        {
            int pk=p.size();
            int pk1=0;
             while(pk1<pk)
             {
                 if(p[pk1]!=c)
                 {
                     last=p[pk1];
                     break;
                 }
                 pk1++;
             }
        if(last>=c)
        {
   for(int j=0;j<si;j++)
        {
             ans=ans+c;
             ms[c]--;
        }
         ans=ans+p;
        }
        else
        {
            ans=ans+p;
              for(int j=0;j<si;j++)
        {
             ans=ans+c;
             ms[c]--;
        }
            
        }
        }
        else
        {
         ans=ans+p;
         for(int j=0;j<si;j++)
        {
             ans=ans+c;
             ms[c]--;
        }
        }
        
        
        //cout<<si<<endl;
     
        c++;
        int key=c-'a';
      while(key<26)
      {
          int siz=ms[c];
          for(int l=0;l<siz;l++)
          {
              ans=ans+c;
          }
          key++;
          c++;
      }

        cout<<ans<<endl;

    }
}