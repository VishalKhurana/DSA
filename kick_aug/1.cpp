#include<bits/stdc++.h>
using namespace std;
int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        int i=1;
        int j=2;
        int count=2;
        int ans=2;
        int diff=arr[1]-arr[0];
        while(j<arr.size()&&i<arr.size())
        {
            if(diff==(arr[j]-arr[i]))
            {
                i++;
                j++;
                count++;
                 ans=max(ans,count);
               // cout<<diff<<endl;
            }
            else
            {
                //cout<<arr[i]<<" "<<arr[j]<<" "<<count<<endl;
               
                diff=(arr[j]-arr[i]);
               // cout<<diff<<endl;
                count=2;
                i++;
                j++;
            }
            
        }
        cout<<"Case"<<" "<<"#"<<p+1<<":"<<" "<<ans<<endl;
    }
}