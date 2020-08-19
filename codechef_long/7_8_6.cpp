#include<bits/stdc++.h>
using namespace std;
//int dp[500001];
void sol(vector<int>&freq,int idx,vector<int>&arr,vector<int>&freqtemp)
{
    if(idx==arr.size())
    {
        int max_=0;
        int index=0;
        //cout<<"hi"<<endl;
        for(int i=0;i<freq.size();i++)
        {
            //cout<<freq[i]<<" ";
            if(max_<freq[i])
            {
                max_=freq[i];
                index=i;
            }
             

        }
        // cout<<endl;
        // cout<<max_<<endl;
           freqtemp[index]++;
           //cout<<"freq"<<" "<<" "<<index<<" "<<freqtemp[index]<<endl;
        return ;
       

    }
   
    sol(freq,idx+1,arr,freqtemp);
   
    freq[arr[idx]]++;
    sol(freq,idx+1,arr,freqtemp);
    freq[arr[idx]]--;
    
}
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
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
        vector<int>freq(n+1,0);
        vector<int>freqtemp(n+1,0);
        //memset(dp,-1,sizeof(dp));
        sol(freq,0,arr,freqtemp);
        for(int i=1;i<freqtemp.size();i++)
        {
            cout<<freqtemp[i]<<" ";

        }
        cout<<endl;



    }
}