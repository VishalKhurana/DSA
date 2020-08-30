#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        int ans=n;
        while(1)
        {
            if(n<=5)
            {
                break;
            }
            ans=ans+n/2;
            n=n/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}