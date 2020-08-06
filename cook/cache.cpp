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
        int n,b,m;
        cin>>n>>b>>m;
        int first;
        int count=0;
         int val=0;
        if(m!=0)
        {
        cin>>first;
         val=first/b;
        count++;
        }
        
        for(int i=1;i<m;i++)
        {
              int inp;
              cin>>inp;
              if(inp/b==val)
              {
                  continue;
              }
              else
              {
                  val=inp/b;
                  count++;
              }
              


        }
        cout<<count<<endl;
    }
}