#include<bits/stdc++.h>
using namespace std;
void biuldTree(int low,int high,vector<int>&arr,vector<int>&seg,int pos)
{
    if(low==high)
    {
        seg[pos]=arr[low];
        return;
    }
    int mid=low+(high-low)/2;
    biuldTree(low,mid,arr,seg,2*pos+1);
    biuldTree(mid+1,high,arr,seg,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    return;

}
int query(int qlow,int qhigh,int low,int high,vector<int>&seg,int pos)
{
    if(qlow<=low&&qhigh>=high)
    {
        return seg[pos];
    }
    if(qlow>high||qhigh<low)
    {
        return 0;
    }
    int mid=low+(high-low)/2;
    return query(qlow,qhigh,low,mid,seg,2*pos+1)
    +query(qlow,qhigh,mid+1,high,seg,2*pos+2);
}
void update(vector<int>&seg,int low,int high,int index,int val,int pos)
{
    if(index<low||index>high)
    {
        return ;
    }
    if(low==high)
    {
        seg[pos]=val;
        return;
    }
    int mid=low+(high-low)/2;
    update(seg,low,mid,index,val,2*pos+1);
    update(seg,mid+1,high,index,val,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];

}
int nextpowerof2(int n)
{
    if(n&&!(n&(n-1)))
    {
        return n;
    }
    int count=0;
    while(n!=0)
    {
        n=n>>1;
        count++;

    }
    return 1<<count;
}
int sol(int n,int q,vector<int>&arr,vector<int>&seg)
{

int sum=0;
biuldTree(0,seg.size()-1,arr,seg,0);
    for(int qq=0;qq<q;qq++)
    {
        char c;
        cin>>c;
        int L,R;
        cin>>L>>R;
        if(c=='Q')
        {
        sum=sum+query(L,R,0,seg.size()-1,seg,0);
        }
        else
        {
            update(seg,0,seg.size()-1,L,R,0);
        }
        

    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        int q;
        cin>>n>>q;
        int size=nextpowerof2(n);
        vector<int>arr;
        vector<int>seg(size,0);
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);

        }
        int ans=sol(n,q,arr,seg);
        cout<<ans<<endl;

    }

    return 0;
}