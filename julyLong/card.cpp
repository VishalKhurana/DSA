#include<bits/stdc++.h>
using namespace std;
 int findDigSum(long long int n)
{
    int sum=0;
    while(n)
    {
  sum=sum+(n%10);
  n=n/10;
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int morphy=0;
        int chef=0;
        for(int i=0;i<n;i++)
        {
            long long int a,b;
            cin>>a>>b;
             int sum_chef=findDigSum(a);
           long int sum_morphy=findDigSum(b);
            if(sum_chef>sum_morphy)
            {
                chef++;
            }
            else if(sum_morphy>sum_chef)
            {
                morphy++;
            }
            else
            {
                morphy++;
                chef++;
            }
            
         }
         if(chef==morphy)
         {
             cout<<2<<" "<<morphy<<endl;
         }
         else if(chef>morphy)
         {
             cout<<0<<" "<<chef<<endl;
         }
         else
         {
             cout<<1<<" "<<morphy<<endl;
         }
    }
}