#include<bits/stdc++.h>
using namespace std ;
bool sol(vector<int>&arr,int n)
{
    int coin_5=0,coin_10=0,coin_15=0;
    for(int i=0;i<n;i++)
    {
       if(arr[i]==5)
       {
           coin_5++;
           continue;
       }
       else if(arr[i]==10)
       {
           if(coin_5==0)
           {
               return false;
           }
           coin_10++;
           coin_5--;
       }
       else
       {
           if((coin_10==0)&&(coin_5<2))
           {
               return false;
           }
           if(coin_10!=0)
           {
               coin_10--;
               coin_15++;
               continue;
           }
           else if(coin_5>1)
           {
               coin_5=coin_5-2;
               coin_15++;
           }
       }
       
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        bool ans=sol(arr,n);
        if(ans)
        {
        cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
        
    }
    return 0;
}