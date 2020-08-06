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
    for(int i=0;i<n;i++)
    {
    vector<Edge*>arr;
    graph.push_back(arr);
    }

}
void addEdge(int u,int v,int w)
{
    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}
int bfs(int src,int des,vector<bool>&vis)
{
    queue<int>que;
    que.push(src);
    vis[src]=true;
    int level=0;
    while(!que.empty())
    {
        int size=que.size();
        while(size>0)
        {
            int front=que.front();
            que.pop();
            if(src==des)
            {
                return level;

            }
            for(int i=0;i<graph[src].size();i++)
            {
                if(!vis[graph[src][i]->v])
                {
                    vis[graph[src][i]->v]=true;
                    que.push(graph[src][i]->v);
                
                }
            }
            size--;
        }
        level++;
    }
    return -1;
}
int bfs_vec(int src,map<int,bool>supplies,vector<bool>&vis)
{
    queue<int>que;
    que.push(src);
    vis[src]=true;
    int level=0;
    while(!que.empty())
    {
        int size=que.size();
        while(size>0)
        {
            int front=que.front();
            que.pop();
            if(supplies[front]==true)
            {
                return level;

            }
            for(int i=0;i<graph[src].size();i++)
            {
                if(!vis[graph[src][i]->v])
                {
                    vis[graph[src][i]->v]=true;
                    que.push(graph[src][i]->v);
                
                }
            }
            size--;
        }
        level++;
    }
    return -1;
}
 int main()
{
    int t;
    cin>>t;
for(int p=0;p<t;p++)
{
int n,s,q,e;
cin>>n>>s>>q>>e;
initialise(n);
for(int i=0;i<n-1;i++)
{
    int u,v,w;
    cin>>u>>v>>w;
    addEdge(u,v,w);
}
map<int,bool>supplies;
for(int j=0;j<s;j++)
{
    int c;
    cin>>c;

   if(supplies.count(c)==0)
    supplies[c]=true;

}
for(int pp=0;pp<q;pp++)
{
    int waste,present;
    cin>>waste>>present;
    if(waste==present)
    {
        cout<<"escaped"<<endl;
        continue;
    }
    vector<bool>vis(n,false);
    int ans_= bfs(present,e,vis);
    if(ans_!=-1)
    {
        cout<<"escaped"<<endl;
    }
    else
    {
         vector<bool>vis_(n,false);
       int ans__= bfs_vec(present,supplies,vis_);
       
       if(ans__!=-1)
       {
           cout<<ans__<<endl;
       }
       else
       {
           cout<<"oo"<<endl;
       }
       
    }
    


}


}
}

    
