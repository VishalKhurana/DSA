#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        if(n<31)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(n==36)
        {
            cout<<"YES"<<endl;
            cout<<5<<" "<<6<<" "<<10<<" "<<15<<endl;

        }
          else if(n==40)
        {
            cout<<"YES"<<endl;
            cout<<9<<" "<<6<<" "<<10<<" "<<15<<endl;

        }
          else if(n==44)
        {
            cout<<"YES"<<endl;
            cout<<13<<" "<<6<<" "<<10<<" "<<15<<endl;

        }
        else
        {
            cout<<"YES"<<endl;
            int k=n-(6+10+14);
            cout<<6<<" "<<10<<" "<<14<<" "<<k<<endl;
        }
        
    }

}