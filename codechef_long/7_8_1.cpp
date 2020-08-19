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
        llt n,k;
        cin>>n>>k;
        vector<llt>arr;
        for(llt i=0;i<n;i++)
        {
            llt val;
            cin>>val;
            arr.push_back(val);
        }
       llt min_ele;
       llt min_diff=INT_MAX;
       for(llt i=0;i<n;i++)
       {
           if(arr[i]>(k/2))
           {
               continue;
           }


           llt diff=k-arr[i];
           if(diff%arr[i]!=0)
           {
               continue;
           }
           llt steps=diff/arr[i];
           if(steps<min_diff)
           {
               min_diff=steps;
               min_ele=arr[i];
           }
       }
       if(min_diff==INT_MAX)
       {
           cout<<-1<<endl;
       }
       else
       {
           cout<<min_ele<<endl;
       }
       

    }
}