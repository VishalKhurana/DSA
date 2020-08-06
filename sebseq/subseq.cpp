#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&sub,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<sub[i]<<",";
    }
    cout<<endl;
}
void subseq(vector<int>sub,vector<int>&arr,int index)
{
    if(index==arr.size())
    {
         int l=sub.size();
         if(l!=0)
         {
             display(sub,l);
         }
    }
    else
    {
        subseq(sub,arr,index+1);
        sub.push_back(arr[index]);
        subseq(sub,arr,index+1);
    }
    
}
//complexity of 2^n.....*--------------------------------------------*----------------------------------*--------------------*---------------- 
int main()
{
    vector<int>arr={1,2,3};
    vector<int>sub;
    subseq(sub,arr,0);
    return 0;
}