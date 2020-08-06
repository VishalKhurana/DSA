#include<bits/stdc++.h>
using namespace std;
long long int sol(vector<long long int>&arr,vector<int>&each,int n,int k)
{
    long long int sum=0;
    int s=0;
    int e=arr.size()-1;
    sort(arr.begin(),arr.end());
    for(int i=0;i<each.size();i++)
    {
       int present=each[i];
        if(present>=1)
        {
            sum=sum+arr[e];
           
            int counter=present-1;
            if(counter==0)
            {
                sum=sum+arr[e];
            }
              e--;
        bool flag=false;
        while(counter--)
        {
            //cout<<present<<endl;
            if(flag==false)
            {
                flag=true;
                sum=sum+arr[s];
            }
            s++;

        
       
       
        }
        }
        
    }
    return sum;

}
int main()
{
  int t;
  cin>>t;
  for(int p=0;p<t;p++)
  {
      int n,k;
      cin>>n>>k;
      vector<long long int>arr;
      for(int i=0;i<n;i++)
      {
          long long int val;
          cin>>val;
          arr.push_back(val);
      }
      vector<int>each;
      for(int i=0;i<k;i++)
      {
          int val;
          cin>>val;
          each.push_back(val);
      }
      long long int ans=sol(arr,each,n,k);
      cout<<ans<<endl;
  }
}