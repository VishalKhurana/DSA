#include<bits/stdc++.h>
// #define long long int  llt;
using namespace std;
long long int count_turns(long long int n)
{
    long long int cnt=0;
    while(1)
    {
        if((n&1)||n<1)
        {
            return cnt;

        }
      //  cnt=cnt/2;
      cnt++;
      n=n/2;
    }
   return cnt;
}
long long int pow(long long int x,  long long int y) 
{ 
    long long int res = 1; 
  
    while (y > 0) { 
        
        if (y & 1) 
            res = res * x; 
  
        
        y = y >> 1; // y = y/2 
        x = x * x; // Change x to x^2 
    } 
    return res; 
} 
long long int sol(long long int n)
{
    if(n==1||n==2)
    {
        return 0;
    }

    if(n&1)
    {
       
        return n/2;
        
    }
    else if(!(n&1))
    {
        long long int count_jerry=0;
        long long int major_score=count_turns(n);
        // cout<<major_score<<endl;
        long long int power=pow(2,major_score+1);
        // cout<<power<<endl;
        if(power==n)
        {
            return 0;
        }
        else
        {
            return n/power;
        }
        
        
     
        // call the number of turns function
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        long long int n;
        cin>>n;
        long long int ans=sol(n);
        cout<<ans<<endl;
    }
    return 0;
}