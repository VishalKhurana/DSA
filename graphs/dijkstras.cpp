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
vector<vector<Edge*>>graph;
void initialise(int n)
{
    graph.clear();
    for(int i=0;i<n;i++)
    {
        vector<Edge*>arr;
        graph.push_back(arr);
    }
}
class node
{
    public:
    int wt;
    int vtx;
    int pvtx;
    int wsf;
    string psf;
    node(int wt,int vtx,int pvtx,int wsf,string psf)
    {
        this->wt=wt;
        this->vtx=vtx;
        this->pvtx=pvtx;
        this->wsf=wsf;
        this->psf=psf;

    }
};
class Compare
{
    public:
    bool operator()(node const &a,node const &b)
    {
        return a.wsf>b.wsf;
    }
};

void addEdge(int u,int v,int w)
{
    graph[u].push_back(new Edge(v,w));

}
int dijkstra(int u,int n)
{
    int ans=INT_MIN;
    vector<int>visited(n+1,false);
    node f(0,u,-1,0,"");
    priority_queue<node,vector<node>,Compare>pq;
    pq.push(f);
    while(!pq.empty())
    {
        int size=pq.size();
        while(size>0)
        {
            node front=pq.top();
            pq.pop();
            if(visited[front.vtx])
            {
                size--;
                continue;
            }
            visited[front.vtx]=true;
             ans=max(ans,front.wsf);
            for(int i=0;i<graph[front.vtx].size();i++)
            {
                if(!visited[graph[front.vtx][i]->v])
                {
                    node s(graph[front.vtx][i]->w,graph[front.vtx][i]->v,front.vtx,front.wsf+graph[front.vtx][i]->w,front.psf+to_string(graph[front.vtx][i]->v));
                    pq.push(s);
                    

                }
                
            }
           size--;

        }
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                ans=-1;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    initialise(n+1);

    for(int i=0;i<3;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    int k;
    cin>>k;
    int ans=dijkstra(k,n);
    cout<<ans<<endl;


    return 0;
}