#include<bits/stdc++.h>
using namespace std;
int findlowest(int n)
{
    while(n&(n-1)!=0)
    {
        n--;
    }
    return n;
}
 int countBits( int n) 
{ 
    int count = 0; 
   while (n) 
   { 
        count++; 
        n >>= 1; 
    } 
    return count; 
} 
   
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int>arr;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            sum=sum+val;
            arr.push_back(val);
        }
        sort(arr.begin(),arr.end());
        int last=arr[n-1];
        int lowest=findlowest(last);
        int bits=countBits(lowest);
        int pure=bits-k;
        if(pure<0)
        {
            cout<<pow(2,k)-1<<endl;
            continue;
             

        }
        int sub=pow(2,pure)-1;
        //cout<<"sub"<<sub<<endl;
        int t=pow(2,bits)-1;
        //cout<<t<<endl;
        int ans=t-sub;
        cout<<ans<<endl;

            
        

    }
}