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
        int n;
        cin>>n;
        vector<int>arr;
        //map<int,int>ma;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
          
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]&arr[j]==arr[i])
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
     


    }
}