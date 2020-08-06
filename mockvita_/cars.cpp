#include<bits/stdc++.h>
using namespace std;
long long int min(long long int a,long long int b)
{
    if(a<b)
    {
        return a;
    }
    return b;

}
double distance(long long int  x1, long long int  y1, long long int  x2, long long int  y2) 
{ 
    
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
} 
long long int binomialCoeff(long long int n, long long int k) 
{ 
    long long int C[n + 1][k + 1]; 
    long long int i, j; 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

int main()
{
   long long int n;
   cin>>n;
   map<double,long long int>m;
   for(int i=0;i<n;i++)
   {
      long long int x,y,s;
      cin>>x>>y>>s;
      double dis=distance(x,y,0,0);
      double time=dis/s;
      m[time]++;
      

   }
   map<double,long long int> :: iterator it;
   long long int ans=0;
   for(it=m.begin();it!=m.end();it++)
   {
       if(it->second>1)
       {
     ans=ans+binomialCoeff(it->second,2);

       }

   }
   cout<<ans<<endl;

}