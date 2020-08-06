#include<bits/stdc++.h>
using namespace std;
int count_bits(int n)
{
    int count=0;
    while(n!=0)
    {
      if(n&1)
      {
          count++;
      }
      n=n>>1;

    }
    return count;
}
int main()
{
    int a=8; //1000
    int b=6; //0110
    int c=a^b; //    1110
    cout<<c<<endl;
    int ans=count_bits(c);
    cout<<ans<<endl;
    return 0;
}