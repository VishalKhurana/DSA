#include<bits/stdc++.h>
using namespace std;
class node
{
  public:
  int distance;
  pair<int,int>pt;
  node(int distance,pair<int,int>pt)
  {
      this->distance=distance;
      this->pt=pt;
  }
};
class Compare
{

public:
  bool operator()(node const& n1,node const &n2)
  {
      return n1.distance>n2.distance;
  }

};
int manhattanDistance(int x1,int y1,int x2,int y2)
{
    int X=(x1-x2)*(x1-x2);
    int Y=(y1-y2)*(y1-y2);
    int dis=X+Y;
    return dis;
}
int main()
{
    int n,k;
    int x1,y1;
    cin>>n>>x1>>y1>>k;
    

    vector<pair<int,int>>points;
    pair<int,int>point;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        pair<int,int>p;
        p.first=x;
        p.second=y;
        points.push_back(p);

    }
    priority_queue<node,vector<node>,Compare>pq;
    for(int i=0;i<n;i++)
    {
        pair<int,int>pt=points[i];
        int dis= manhattanDistance(pt.first,pt.second,x1,y1);
        node temp(dis,pt);
        pq.push(temp);

    }
    for(int i=0;i<k;i++)
    {
        node res=pq.top();
        pair<int,int>resPair=res.pt;
        cout<<resPair.first<<" "<<resPair.second<<endl;
        pq.pop();

    }

}