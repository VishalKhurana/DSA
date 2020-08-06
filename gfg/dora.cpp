#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int freq;
    int id;
    node(int id,int freq)
    {
        this->id=id;
        this->freq=freq;
    }
};
class Compare { 
    public:
    bool operator()(node const& n1, node const& n2) 
    { 
        if(n1.freq==n2.freq)
        {
            return n2.id>n1.id;
        }
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return n1.freq < n2.freq; 
    } 
}; 
void sol(priority_queue<node,vector<node>,Compare>&pq,int n,int k)
{
    while(k!=0&&!pq.empty())
    {
        node n=pq.top();
        pq.pop();
       
            k--;
            cout<<n.id<<" ";
        
        
       
    }
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        vector<int>arr;
        priority_queue<node,vector<node>,Compare>pq;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            m[val]++;
        }
    map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            node n(it->first,it->second);
            pq.push(n);



        }
        int k;
        cin>>k;
        sol(pq,n,k);
    }
    return 0;
}