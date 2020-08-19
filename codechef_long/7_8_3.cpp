#include<bits/stdc++.h>
#define llt long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
      llt c,r;
      cin>>c>>r;
      llt cf=c/9;
      llt cm=c%9;
      llt rf=r/9;
      llt rm=r%9;
      llt cp,rp;
      if(cm==0)
      {
          cp=cf;
      }
      else
      {
          cp=cf+1;
      }

       if(rm==0)
      {
          rp=rf;
      }
      else
      {
          rp=rf+1;
      }

      if(rp<=cp)
      {
          cout<<1<<" "<<rp<<endl;
      }
      else
      {
          cout<<0<<" "<<cp<<endl;
      }
      
      

    }
}