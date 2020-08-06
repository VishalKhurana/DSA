#include<bits/stdc++.h>
using namespace std;
class Edge{
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
void addEdge(int u,int v,int w)
{
    graph[u].push_back(new Edge(v,w));
}
void initialise(int n)
{
    for(int i=0;i<n;i++)
    {
        vector<Edge*>arr;
        graph.push_back(arr);
    }
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<"->"<<graph[i][j]->v<<" "<<graph[i][j]->w<<endl;
        }
    }
}
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vector<int>visited(7,false);
    visited[src]=true;
    while(!q.empty())
    {
        int size=q.size();
        while(size>0)
        {
            int ref=q.front();
            q.pop();
            cout<<ref<<" ";
            for(int i=0;i<graph[ref].size();i++)
            {
                if(!visited[graph[ref][i]->v])
                {
                q.push(graph[ref][i]->v);
                visited[graph[ref][i]->v]=true;
                }
            }
            size--;
        }
        cout<<endl;
    }


}
bool isCyclic(int src,vector<int>&rec,vector<bool>&vis)
{
    if(vis[src]==false)
    {
        rec[src]=true;
        vis[src]=true;
        for(int i=0;i<graph[src].size();i++)
        {
        if(!vis[graph[src][i]->v]&&isCyclic(graph[src][i]->v,rec,vis))
        {
            return true;
        }
        else if(rec[graph[src][i]->v])
        {
            return true;
        }
        }
    }
    rec[src]=false;
    return false;

}
void dfs(int src,vector<bool>&visited)
{
   visited[src]=true;
   cout<<src<<endl;
   for(int i=0;i<graph[src].size();i++)
   {
       if(!visited[graph[src][i]->v])
       {
          visited[graph[src][i]->v]=true;
        dfs(graph[src][i]->v,visited);
       }
   }

}

int main()
{
    initialise(7);
    addEdge(0,1,5);
    addEdge(0,3,5);
    addEdge(1,2,5);
    addEdge(3,2,5);
    addEdge(2,4,5);
    addEdge(5,4,5);
    addEdge(5,6,5);
    addEdge(4,6,5);
    //display();
    //bfs(0);
    
    // dfs(0,visited);
    vector<bool>visited(7,false);
    vector<int>rec(7,0);
    return 0;
}
