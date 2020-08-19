#include<bits/stdc++.h>
using namespace std;
int get_power(long n)
{
    while(1)
    {
        if(((n)&(n-1))==0)
        {
            break;
        }
        n++;
    }
    //cout<<n<<endl;
    int count=0;
    while(n!=1)
    {
        count++;
        n/=2;

    }
    return count;


}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        long n;
        cin>>n;
        if(n==1)
        {
            cout<<"Richard"<<endl;
            continue;
        }
        int ps=get_power(n);
        //cout<<ps<<endl;
       // ps--;
    
        if(ps%2!=0)
        {
            cout<<"Richard"<<endl;
        }
        else
        {
            cout<<"Louise"<<endl;
        }

    }
}