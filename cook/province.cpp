#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int province;
  int income;
  int population;
  int ratio;
  node(int province,int income,int population,int ratio)
  {
   this->province=province;
   this->income=income;
   this->population=population;
   this->ratio=ratio;
  }
};
class Edge
{
public:
int v;
Edge(int v)
{
    this->v=v;
   
}

};
vector<vector<Edge*>>graph;
void addEdge(int u,int v)
{
    graph.clear();
    graph[u].push_back(new Edge(v));
    graph[v].push_back(new Edge(u));
}

void initilaise(int n)
{
    graph.clear();
    vector<Edge*>arr;
    for(int i=0;i<n;i++)
    {
        graph.push_back(arr);
    }
}

class compare
{
    public:
    bool operator()(node a,node b)
    {
       return a.ratio<b.ratio;
    }

};
class ans
{
    public:
    int n;
    vector<int>pro;
    ans(int n,vector<int>pro)
    {
        this->n=n;
        this->pro=pro;
    }

};
ans bfs(int src,vector<bool>&vis)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    int k=0;
    vector<int>kans;
    while(!q.empty())
    {
        int size=q.size();
        while(size>0)
        {
            int front=q.front();
            q.pop();
            k++;
            kans.push_back(front);
            
            for(int i=0;i<graph[front].size();i++)
            {
                if(!vis[graph[front][i]->v])
                {
                    q.push(graph[front][i]->v);
                    vis[graph[front][i]->v]=true;
                }
            }
            size--;

        }

    }
    ans k_(k,kans);
    return k_;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>income;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            income.push_back(val);
        }
        vector<int>population;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            population.push_back(val);
        }
        initilaise(n+1);
        for(int j=0;j<m;j++)
        {
            int u,v;
            cin>>u>>v;
            addEdge(u,v);
            
        }
        priority_queue<node,vector<node>,compare>pq;
        for(int i=0;i<n;i++)
        {
            int rate=income[i]/population[i];
            node n(i+1,income[i],population[i],rate);
            pq.push(n);
        }
        int sum=0;
        int khandan=0;
        int ratioo=0;
        vector<bool>vis(n+1,false);
       if(!pq.empty())
       {
        node s=pq.top();
        pq.pop();
        sum=s.income;
        khandan=s.population;
        ratioo=s.ratio;
       }
       bool flag=false;
       while(!pq.empty())
       {
           node top=pq.top();
           pq.pop();
           if(top.ratio<ratioo)
           {
               vis[top.province]=true;
               flag=true;
               break;

           }
       }
       if(flag==true)
       {
           while(!pq.empty())
           {
               node top_=pq.top();
               pq.pop();
               vis[top_.province]=true;
           }
       }
     
       int max_=INT_MIN;
       vector<int>mera;
       for(int i=1;i<=n;i++)
       {
           if(vis[i]==false)
           {
               ans touch=bfs(i,vis);
               if(max_<touch.n)
               {
                   mera.clear();
                   for(int b=0;b<touch.pro.size();b++)
                   {
                       mera.push_back(touch.pro[b]);
                   }
                   
                   max_=touch.n;
               }

                          }
       }
       cout<<max_<<endl;
       for(int h=0;h<mera.size();h++)
       {
           cout<<mera[h]<<" ";
       }
       cout<<endl;



    
    }
}