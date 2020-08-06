#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int v;
    int w;
    Edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }

};
class Edge1
{
    public:
    int u;
    int v;
    int w;
    Edge1(int v,int u,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }

};

vector<vector<Edge*>>graph;
void initialise(int n)
{
    for(int i=0;i<n;i++)
    {
    vector<Edge*>arr;
    graph.push_back(arr);
    dgraph.push_back(arr);
    
    }
}
void addEdge(int u,int v,int w)
{
    graph[u].push_back(new Edge(v,w));
}
void addEdge01(int u,int v,int w)
{
    dgraph[u].push_back(new Edge(v,w));
}
class Compare
{
    bool operator()(Edge1*const&a,Edge1*const&b)
    {
        return a->w>b->w;
    }
};
vector<vector<Edge*>>dgraph;
int find(vector<int>parent, int i)  
{  
    if (parent[i] == i)  
        return i;  
    return find(parent, parent[i]);  
}  

void Union(vector<int>parent, int x, int y)  
{  
    int xset = find(parent, x);  
    int yset = find(parent, y);  
    if(xset != yset) 
    {  
        parent[xset] = yset;  
    }  
}  

bool isCycle(int u,int v,int n,vector<int>&parent)
{
    

  
    // Iterate through all edges of graph, find subset of both  
    // vertices of every edge, if both subsets are same, then  
    // there is cycle in graph.  
   
        int x = find(parent, u);  
        int y = find(parent, v);  
  
        if (x == y)  
            return 1;  
  
      
     
    return 0; 
}

void buildTree(priority_queue<Edge1*,vector<Edge1*>,Compare>&pq,int n)
{
    int count=0;
     vector<int>parent(n,-1);
     for(int i=0;i<n;i++)
     {
         parent[i]=i;
     }
    
    while(count!=n-1&&!pq.empty())
    {
    Edge1*a=pq.top();
    pq.pop();
    vector<int>parent(n+1);
    //cout<<a->u<<a->v<<a->w<<endl;
    if(!isCycle(a->u,a->v,n,parent))
    {
        addEdge01(a->u,a->v,a->w);
        parent[a->u]=a->v;
        count++;
    }
    }


}
int main()
{
    priority_queue<Edge1*,vector<Edge1*>,Compare>pq;
    int n;
    cin>>n;
    initialise(n+1);
    for(int i=0;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Edge1*a=new Edge1(u,v,w);
        pq.push(a);
    }
    buildTree(pq,n);

  return 0;
}