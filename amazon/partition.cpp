#include<bits/stdc++.h>
using namespace std;
vector<string>sol(string s)
{
    vector<string>ans;
    map<char,priority_queue<int>>m;
    for(int i=0;i<s.size();i++)
    {
        m[s[i]].push(i);
    }
    int end=s.size()-1;
    for(int i=0;i<s.size();i++)
    {
        int e=m[s[i]].top();
        string a=s.substr(i,e-i+1);
        ans.push_back(a);
       
        i=e;


    }
    return ans;

}
int main()
{
    string s;
    cin>>s;
    vector<string>ans=sol(s);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    // string g=s.substr(0,2);
    // cout<<g<<endl;
    return 0;
}