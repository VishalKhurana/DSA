#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000][2];
void getDigits(int n,vector<int>&digits)
{
    while(n)
    {
        int r=n%10;
        digits.push_back(r);
        n=n/10;
    }
    reverse(digits.begin(),digits.end());
}
int getsum(int pos,int sum,int tight,vector<int>&digits)
{
    if(pos>digits.size())
    {
        return 0;
    }
    if(pos==digits.size())
    {
        return sum;
    }
    if(dp[pos][sum][tight]!=-1)
    {
        return dp[pos][sum][tight];
    }
    int limit=(tight==1)?digits[pos]:9;
    int res=0;
    for(int i=1;i<=limit;i++)
    { 
        int new_sum=sum+i;
        int new_tight=((tight==1)&&i<limit)?0:tight;
        res+=getsum(pos+1,new_sum,new_tight,digits);
    
    }
    return dp[pos][sum][tight]=res;
      
}
int main()
{
    int n;
    cin>>n;
    vector<int>digits;
    memset(dp,-1,sizeof(dp));
    getDigits(n,digits);
    int ans=getsum(0,0,1,digits);
    cout<<ans<<endl;

}