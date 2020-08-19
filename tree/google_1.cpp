#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int v;
    node*left=NULL;
    node*right=NULL;
    node(int v)
    {
        this->v=v;

    }
};
bool sol(node*root,int &count)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        count++;
        return true;
    }
    bool left=sol(root->left,count);
    bool right=sol(root->right,count);
    if(left&&right)
    {
        if(root->left&&root->right)
        {
        if(root->v==root->left->v&&root->v==root->right->v)
        {
            cout<<"count"<<" "<<count<<endl;
            count++;
            return true;
        }
        }
        else if(!root->left&&root->right)
        {
             if(root->v==root->right->v)
        {
            count++;
            return true;
        }
            
        }
        else if(root->left&&!root->right)
        {
             if(root->v==root->left->v)
            {
            count++;
            return true;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    queue<node*>q;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<pow(2,i);j++)
        {
        int val;
        cin>>val;
        node*temp=new node(val);
        q.push(temp);
        }
    }
    queue<node*>ro;

  node*rt=new node(q.front()->v);
  node*ref=rt;
  ro.push(rt);
  while(!ro.empty()&&!q.empty())
    {
        int size1=ro.size();
        int size2=q.size();
        while(size1>0&&size2>0)
        {

            node*lf=q.front();
            q.pop();
            size2--;
            node*ri=nullptr;
            if(q.size()!=0)
            {
               ri=q.front();
               q.pop();
               size2--;
            }
            node*root=ro.front();
            ro.pop();
            root->left=lf;
            root->right=ri; 
            ro.push(lf);
            ro.push(ri);
            size1--;
            
}
    }
    int count=0;
    bool ans=sol(ref,count);
    cout<<count-1<<endl;
  
  

}