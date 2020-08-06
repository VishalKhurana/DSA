#include<bits/stdc++.h>
using namespace std;
class zombies
{
    public:
    int i;
    int j;
    int infectTurn;
    zombies(int i,int j,int infectTurn)
    {
        this->i=i;
        this->j=j;
        this->infectTurn=infectTurn;
    }
};
void addZombie(int i,int j,int infectturn,queue<zombies>&q,vector<vector<int>>&mat)
{
      mat[i][j]=1;
    zombies z(i,j,infectturn);
    q.push(z);


}
void infect(int i,int j,int turn,vector<vector<int>>&mat,queue<zombies>&q)
{
    if(i-1>=0&&mat[i-1][j]==0)
    {
             addZombie(i-1,j,turn,q,mat);
    }
    if(i+1<mat.size()&&mat[i+1][j]==0)
    {
             addZombie(i+1,j,turn,q,mat);
    }
    if(j-1>=0&&mat[i][j-1]==0)
    {
             addZombie(i,j-1,turn,q,mat);
    }
    if(j+1<mat[0].size()&&mat[i][j+1]==0)
    {
             addZombie(i,j+1,turn,q,mat);
    }
        
}
int sol(vector<vector<int>>&mat,int n,int m)
{
    queue<zombies>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                addZombie(i,j,0,q,mat);
            }
            
        }
    }
    int turn=0;
    while(!q.empty())
    {
        
        zombies front=q.front();
        q.pop();
        turn =front.infectTurn;
        infect(front.i,front.j,front.infectTurn+1,mat,q);



    }
    bool human=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;i++)
        {
            if(mat[i][j]==0)
            {
                human=true;
                break;
            }
        }
    }
    return human?-1:turn;

}
int main()
{
int n,m;
cin>>n>>m;
vector<vector<int>>mat(n,vector<int>(m));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        int val;
        cin>>val;
        mat[i][j]=val;
    }
}
int ans=sol(mat,n,m);
cout<<ans<<endl;



    return 0;
}