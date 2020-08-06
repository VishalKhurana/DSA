#include<bits/stdc++.h>
using namespace std;
bool sol(  priority_queue<int,vector<int>,greater<int>>&b,  priority_queue<int,vector<int>,greater<int>>g,int n)
{
    bool boy=false,girl=false;
    while(!b.empty()&&!g.empty())
    {
      if((g.top()<=b.top())&&girl==false)
      {
          g.pop();
          girl=true;
          boy=false;
      }
      else if((b.top()<=g.top())&&boy==false)
      {
          b.pop();
          boy=true;
          girl=false;
      }
      else
      {
          return false;
      }
      
    }
    if(b.size()>1||g.size()>1)
    {
        return false;
    }
    if(!b.empty()&&boy==true)
    {
             return false;
    }
    if(!g.empty()&&girl==true)
    {
             return false;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>>b;
        priority_queue<int,vector<int>,greater<int>>g;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            b.push(val);
        }
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            g.push(val);
        }
        //  for(int i=0;i<n;i++)
        // {
            
            
        //     cout<<g.top()<<endl;
        //     g.pop();
        // }
        bool ans=sol(b,g,n);
        if(ans)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}