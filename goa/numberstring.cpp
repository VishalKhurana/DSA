#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int count=0;
    map<char,int>m;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;

    }
    map<char,int>temp;
    bool flag=false,yes=false;
    map<char,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        temp[s[i]]++;
        m[s[i]]--;
        if(m[s[i]]==0)
        {
            m.erase(s[i]);
        }
        flag=false;
        if(temp.size()==m.size())
        {
            //cout<<temp.size()<<" "<<m.size()<<endl;
            for(it=m.begin();it!=m.end();it++)
            {
                if(temp.count(it->first)==0)
                {
                       flag=true;
                       break;
                }

            }
            if(flag==false)
            {
                //cout<<"hi"<<endl;
                count++;
                //yes=true;
            }


        }
        
    }
    cout<<count<<endl;
    return 0;
}