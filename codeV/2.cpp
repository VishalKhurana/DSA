#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int one,zero;
    node(int one,int zero)
    {
        this->one=one;
        this->zero=zero;
    }
};
node checkBinary(int n,int calBits)
{
    int one=0,zero=0;
    while(calBits)
    {
        if(n&1)
        {
            one++;

        }
        else
        {
            zero++;
        }
        n=n>>1;
        calBits--;
    }
    node ans(one,zero);
    return ans;
}
 void decToBinary(int n,int calBits) 
{ 
    calBits--;
    
    for (int i = calBits; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            cout << "1"; 
        else
            cout << "0"; 
    }
    cout<<endl; 
}  

  
int calBits(int n)
{
    int count=0;
    while(n)
    {
        count++;
        n=n>>1;

    }
    return count;
}
void sol(int idx,int &count,vector<int>&arr,map<int,int>&m,int calBits,int n)
{
    if(idx==n)
    {
        if(m[0]==m[1])
        {
            count++;
        }
        return;
    }
    sol(idx+1,count,arr,m,calBits,n);
    node ans=checkBinary(arr[idx],calBits);
    int one=ans.one;
    int zero=ans.zero;
    m[1]=m[1]+one;
    m[0]=m[0]+zero;
    sol(idx+1,count,arr,m,calBits,n);
    m[1]=m[1]-one;
    m[0]=m[0]-zero;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr;
    int max_=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        max_=max(max_,val);
        arr.push_back(val);
    }
    int calans=calBits(max_);
    //cout<<"calans"<<calans<<endl;
    int count=0;
    map<int,int>m;
    m[0]=0;
    m[1]=0;
    sol(0,count,arr,m,calans,n);
    int real_count=count-1;
    decToBinary(real_count,calans);
    //cout<<ans<<endl;



}