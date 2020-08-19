#include<bits/stdc++.h>
using namespace std;
class Trie
{
    public:
    int val;
    Trie*child[2];
    Trie()
    {
        child[0]=NULL;
        child[1]=NULL;
    }
};
Trie *newNode() 
{ 
    Trie *temp = new Trie; 
    temp->val = 0; 
    temp->child[0] = temp->child[1] = NULL; 
    return temp; 
} 
Trie*root;
void insert(int val)
{
    Trie*temp=root;
    for(int i=31;i>=0;i--)
    {
        bool Bval= val&(1<<i);   // get the msb current bit
        if(temp->child[Bval]==NULL)
        {
            temp->child[Bval]= newNode();
        }
        temp=temp->child[Bval];
    }
    temp->val=val;
}

int getMax(int x)
{
    Trie*temp=root;
    for(int i=31;i>=0;i--)
    {
        bool Bval=x&(1<<i);
        if(temp->child[1-Bval]!=NULL)
        {
            temp=temp->child[1-Bval];
        }
        else if(temp->child[Bval]!=NULL)
        {
            temp=temp->child[Bval];
        }

        
    }
    return temp->val^x;

}
int main()
{
    
    int n;
   cin>>n;
    root= newNode();
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        insert(val);
        
    }
    int m;
    cin>>m;
  
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
         int ans=getMax(val);
         cout<<ans<<endl;
       
    }



}