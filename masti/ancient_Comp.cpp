#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
   int t;
   cin>>t;
   for(int p=0;p<t;p++)
   {
       int a,b;
       cin>>a>>b;
       if(a<b)
       {
           swap(a,b);
       }
       int count=0;
       
       while((a>b)&&(~a&1))
       {
         
         count++;
         a=a>>1;
       }
       
       cout<<(a!=b?-1:(count+2)/3)<<endl;
   }
}