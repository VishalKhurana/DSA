#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int freq1;
    int freq2;
    node(int freq1,int freq2)
    {
        this->freq1=freq1;
        this->freq2=freq2;
    }
};
class Compare
{
    public:
    bool operator()(node const&n1,node const&n2)
    {
        return n1.freq1>n2.freq1;
    }
};
int main()
{
    priority_queue<node,vector<node>,Compare>pq;
    for(int i=0;i<10;i++)
    {
        int val;
        cin>>val;
        int val2;
        cin>>val2;
        node k(val,val2);
        pq.push(k);
    }
    cout<<"result"<<endl;
    while(!pq.empty())
    {
        cout<<pq.top().freq1<<" "<<pq.top().freq2<<endl;
        pq.pop();
       
    }
    

}