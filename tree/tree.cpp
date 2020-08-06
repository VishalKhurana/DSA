#include<bits/stdc++.h>
using namespace std;
class node
{
public:
int data;
 node*left=NULL;
 node*right=NULL;
 node(int data)
 {
     this->data=data;
 }
};
void inorder(node*root)
{
    if(root==NULL)
    {
        return ;
    }

    inorder(root->left);
   cout<<root->data<<" ";
    inorder(root->right);
}
int dfs(node*root,int val)
{
    if(root==NULL)
    {
        return -1;

    }
    if(root->data==val)
    {
        return 0;
    }
    int lf=dfs(root->left,val);
    int ri=dfs(root->right,val);
    if(lf!=-1)
    {
        return 1+lf;
    }
    else if(ri!=-1)
    {
        return 1+ri;
    }
    return -1;
 
}
void downdistanceK(node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    downdistanceK(root->left,k-1);
    downdistanceK(root->right,k-1);

}
void printAtDistanceK(node*root,node*ref,int k)
{
      int ansL=dfs(root->left,ref->data);
      int ansR=dfs(root->right,ref->data);
      downdistanceK(ref,k);
      if(ansL+1==k)
      {
          cout<<root->data<<" ";
          downdistanceK(root->left,k-1);
      }
      else if(ansR+1==k)
      {
              cout<<root->data<<" ";
          downdistanceK(root->right,k-1);
      }
      else if(ansL!=-1&&ansL+1>k)
      {
          downdistanceK(root->left,ansL+1-k);
      }
      else if(ansR!=-1&&ansR+1>k)
      {
          downdistanceK(root->right,ansL+1-k);
      }
      else if(ansL!=-1&&ansL+1<k)
      {
          downdistanceK(root->right,k-ansL+1);
      }
      else
      {
          downdistanceK(root->left,k-ansR+1);
      }
      
      



}

int main()
{
    int n;
    cin>>n;
    int val;
    cin>>val;
    node*root=new node(val);
    node*ref=root;
    queue<node*>q;
    //q.push(root);
    for(int i=0;i<n-1;i++)
    {
        int val;
        cin>>val;
        node*temp=new node(val);
        q.push(temp);
    }
    queue<node*>ro;
    ro.push(root);
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
     //inorder(root);
    //  int ans=dfs(root,8);
     //cout<<ans<<endl;
     node*ref1=root->left->left;
printAtDistanceK(root,ref1,3);



    return 0;
}