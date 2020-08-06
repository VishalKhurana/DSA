#include<bits/stdc++.h>
using namespace std;
void sol(vector<int>&arr,int n,int q,int p)
{
    vector<int>res;
    int count=0;
    cout<<"Case "<<"#"<<p+1<<":";
    for(int qq=0;qq<q;qq++)
    {
        res.clear();
        int s,k;
        cin>>s>>k;
        while(count<n)
        {
            if(arr[s]>=arr[s-1])
            {
                s--;
                res.push_back(s-1);
                count++;

            }
            else
            {
                s++;
                res.push_back(s);
                count++;
            }
            
        }
         cout<<" "<<res[k-1]<<endl;
        
    }

}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        int q;
        cin>>n;
        cin>>q;
        vector<int>arr;
        arr.push_back(INT_MAX);
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        arr.push_back(INT_MAX);
        sol(arr,n,q,p);

    }
}