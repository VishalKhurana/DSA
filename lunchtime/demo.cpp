#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int sum=0;
        int s,n;
        cin>>s>>n;
        if(s==n)
        {
            cout<<1<<endl;
            continue;
        }
        if(s>n)
        {
            if(s%n==0)
            {
                cout<<1<<endl;
                continue;
            }
            else if(s>n)
            {
                sum=sum+(s/n);
                int rem=s%n;
                if(rem%2==0)
                {
                    sum=sum+1;
                    cout<<sum<<endl;
                    continue;
                }
                else
                {
                    sum=sum+2;
                    cout<<sum<<endl;
                    continue;
                }
                


            }
            else
            {
                 int rem=s%n;
                if(rem%2==0)
                {
                    sum=sum+1;
                    cout<<sum<<endl;
                    continue;
                }
                else
                {
                    sum=sum+2;
                    cout<<sum<<endl;
                    continue;
                }
            }
            

        }

    }
}