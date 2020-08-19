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
        llt a,b;
        cin>>a>>b;
        while(1)
        {
            a=a-b;
          
            b=b/2;
            
            if(a<=0)
            {
               
                cout<<1<<endl;
                break;
            }
            if(b<=0)
            {
               
                cout<<0<<endl;
                break;
            }
        }
        


    }
}