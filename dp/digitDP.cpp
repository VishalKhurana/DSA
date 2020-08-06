#include<bits/stdc++.h>
using namespace std;

void getDigits(int n,vector<int>&digits)
{
    while(n)
    {
        digits.push_back(n%10);
        n=n/10;
    }
}
int dp[50][250][2];
int sumOfDigits(int pos,int sum,vector<int>&digits,int tight)
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
    //cout<<"lim"<<a<<" "<<limit<<endl;
    int ret=0;
    for(int i=1;i<=limit;i++)
    {
        int new_sum=sum+i;
        int new_tight=(tight==1&&i<limit)?0:tight;
        ret+=sumOfDigits(pos+1,new_sum,digits,new_tight);
        

    }
    //cout<<a<<ret<<endl;
return dp[pos][sum][tight]=ret;;
}

int main()
{
    int a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));

    vector<int>digitsA;
    vector<int>digitsB;

    getDigits(a,digitsA);
    getDigits(b,digitsB);

    reverse(digitsA.begin(),digitsA.end());
    reverse(digitsB.begin(),digitsB.end());

    int ans1=sumOfDigits(0,0,digitsA,1);
    memset(dp,-1,sizeof(dp));
    int ans2=sumOfDigits(0,0,digitsB,1);
  
    cout<<(ans1-ans2)<<endl;




    return 0;
}