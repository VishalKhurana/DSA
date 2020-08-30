#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
vector<int> getdigits(int num)
{
    vector<int>dig;
    
    while(num)
    {
        int r=num%10;
        dig.push_back(r);
        num=num/10;
    }
    reverse(dig.begin(),dig.end());
    return dig;

}
int get_num(int pos,int rem,int num,vector<int>&digs,int size)
{
    if(pos==size)
    {
        return (rem==0);
    }

    if(dp[pos][rem]!=-1)
    {
        return dp[pos][rem];
    }
    if(pos+1<=size)
    {
    dp[pos][rem]=get_num(pos+1,(rem*10+digs[pos])%8,num,digs,size);
    }

     if(pos+1<=size)
    {
    dp[pos][rem]+=get_num(pos+1,rem,num,digs,size);
    }

    return dp[pos][rem];




}
int main()
{
    int n;
    cin>>n;
    int num;
    cin>>num;
    vector<int>digs=getdigits(num);
    memset(dp,-1,sizeof(dp));
    int size=digs.size();
    int ans= get_num(0,0,num,digs,size);
    cout<<ans-1<<endl;

    
}