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
        int n,k;
        cin>>n>>k;
        vector<int>arr;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        int i=0;
      
        bool flag=false;
        while(i<arr.size())
        {
            if(arr[i]>k)
            {
                flag=true;
                break;
            }
            int sum=0;
            while(sum<=k&&i<arr.size())
            {
                if(arr[i]>k)
                {
                    flag=true;
                    break;
                }
                sum=sum+arr[i];
                i++;
            }
            if(sum>k)
            {
                sum=sum-arr[i];
                i--;
            }
            if(flag)
            {
                break;
            }
            count++;
        }
        if(flag)
        {
            count=-1;
        }
        cout<<count<<endl;
    }
    return 0;
}