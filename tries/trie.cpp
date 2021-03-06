#include <bits/stdc++.h> 
#include<vector>
using namespace std;

class trie
{
    public:
    trie*child[26];
    bool isend;
    trie()
    {
      memset(child,0,sizeof(child));
        
        isend=false;
    }
};

trie* root;
void insert(string str)
{
    trie*cur=root;
    for(char ch:str)
    {
        int idx=ch-'a';
        if(cur->child[idx]==NULL)
        {
            cur->child[idx]=new trie();        

        }
        cur=cur->child[idx];
    }
    cur->isend=true;
}
bool search (string str)
{
    trie*cur=root;
    for(char ch:str)
    {
        int idx=ch-'a';
        if(cur->child[idx]==NULL)
        {
            return false;
        }
        cur=cur->child[idx];
    }
    return cur->isend;
}
int main()
{
    int n;
    cin>>n;
    root=new trie();
    while(n--)
    {
        string s;
        cin>>s;
        insert(s);
    }
    int c;
    cin>>c;
    while(c--)
    {
        string st;
        cin>>st;
        if(search(st))
        {
            cout<<st<<" "<<" is present"<<endl;
        }
        else
        {
            cout<<st<<" "<<"is not present"<<endl;
        }
        
    }
    cout<<"done"<<endl;
    return 0;
}