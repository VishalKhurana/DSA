#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int v;
    node*left;
    node*right;
    node(int v)
    {
        this->v=v;
        this->left=NULL;
        this->right=NULL;
    }
};

node *insertvalue(node*root,int val,queue<node*>&q)
{
    node*Node=new node(val);
    if(root==NULL)
    {
        root=Node;


    }

    else if(q.front()->left==NULL)
    {
        q.front()->left=Node;
    }
    else
    {
        q.front()->right=Node;
        q.pop();
    }
    q.push(Node);
    return root;
    

}
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
           // cout<<"count"<<" "<<count<<endl;
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
       // return true;
    }
    return false;
}

node*createTree(vector<int>&arr,int n)
{
    node*root=NULL;
    queue<node*>q;
    for(int i=0;i<n;i++)
    {
        root=insertvalue(root,arr[i],q);

    }
    return root;

}
void levelOrder(node* root) 
{ 
    if (root == NULL) 
        return; 
    queue<node*> n; 
    n.push(root); 
    while (!n.empty()) { 
        cout << n.front()->v<< " "; 
        if (n.front()->left != NULL) 
            n.push(n.front()->left); 
        if (n.front()->right != NULL) 
            n.push(n.front()->right); 
        n.pop(); 
    } 
} 
int main()
{
     int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<pow(2,i);j++)
        {
        int val;
        cin>>val;
        arr.push_back(val);
        
        }
    }
   // cout<<arr.size()<<endl;
    node *root=createTree(arr,arr.size());
    int count=0;
    bool ans=sol(root,count);
    cout<<count<<endl;
    //levelOrder(root);

    return 0;
}
