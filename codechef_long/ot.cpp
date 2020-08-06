#include<bits/stdc++.h>
using namespace std;
int sol(int a,int b,int c,int p,int q,int r)
{
    int count=0;
    while(1)
    {
        if(a==p&&b==q&&c==r)
        {
             return count;
        }
        int diff_a=p-a;
        int diff_b=q-b;
        int diff_c=r-c;
        vector<bool>vis(3,false);
        int countr=0;
        if(diff_a>=a)
        {
            countr++;
            vis[0]=true;
        }
        if(diff_b>=b)
        {
            countr++;
            vis[1]=true;
        }
                if(diff_c>=c)
        {
            countr++;
            vis[2]=true;
        }
        if(countr>1)
        {
            vector<int>gcd_;
           for(int i=0;i<3;i++)
           {
               if(vis[i]==true)
               {
                   if(i==0)
                   {
                       int a_=diff_a/a;
                       if(a_==0)
                       {
                           continue;
                       }
                       gcd_.push_back(a_);
                   }
                   else if(i==1)
                   {
                       int b_=diff_b/b;
                       if(b_==0)
                       {
                           continue;
                       }
                       
                       gcd_.push_back(b_);
                   }
                   else
                   {
                       int c_=diff_c/c;
                        if(c_==0)
                       {
                           continue;
                       }
                       gcd_.push_back(c_);
                   }
                   
               }
           }
           int ans=1;
           for(int i=0;i<gcd_.size();i++)
           {
               ans=gcd(ans,gcd_[i]);
           }
           for(int i=0;i<3;i++)
           {
               if(vis[i]==true)
               {
                      if(i==0&&diff_a!=0)
                   {
                      a=a*ans;
                   }
                   else if(i==1&&diff_b!=0)
                   {
                      b=b*ans;
                   }
                   else if(i==2&&diff_c!=0)
                   {
                      c=c*ans;
                   }

               }
           }
           count++;
        }
        else
        {
            if(diff_a!=0&&diff_b!=0&&diff_c!=0)
            {
            min_=min(diff_a,min(diff_b,diff_c));
            a=a+min_;
            b=
            }


        }
        
    }
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int a,b,c,p,q,r;
        cin>>a>>b>>c;
        cin>>p>>q>>r;
        int ans=sol(a,b,c,p,q,r);
        cout<<ans<<endl;
    }
    
    return 0;
}