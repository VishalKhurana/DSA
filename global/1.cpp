#include<bits/stdc++.h>
using namespace std;
 long long int sol( long long int a, long long int b, long long int n)
 {
      long long int count=0;
      while(1)
      {
          if(a>n||b>n)
          {
              break;
          }
          if(a<b)
          {
              a=a+b;
              count++;
          }
          else
          {
              b=b+a;
              count++;
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
        long long int n;
        long long int a;
        long long int b;
        
        cin>>a;
        cin>>b;
        cin>>n;
        long long ans=sol(a,b,n);
        cout<<ans<<endl;

    }
}