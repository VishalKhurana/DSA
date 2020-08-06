#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n,m;
        cin>>n>>m;
        vector<long long int>arr;
       // int occurences=0;
        for(int i=0;i<n;i++)
        {
            long long int val;
            cin>>val;
        //     if(val==m)
        //     {
        // occurences++;
        //     }
            arr.push_back(val);
        }
        sort(arr.begin(),arr.end());
        long long int ans1=0;
        long long int ans2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<m)
            {
                ans1++;
            }
            else if(arr[i]>m)
            {
                ans2++;
            }

        }
        if(ans1>=(m-1))
        {
            cout<<(ans1+ans2)<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        


    }
}