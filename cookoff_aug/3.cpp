#include<bits/stdc++.h>
using namespace std;

int bfs
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        vector<int>ax;
        vector<int>ay;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            ax.push_back(x);
            ay.push_back(y);

        }
        vector<int>color(n+1);
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            color[i+1]=s[i];
            

        }

    }
}