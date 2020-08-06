#include<bits/stdc++.h>
using namespace std;
vector<int>merge(vector<int>&left,vector<int>&right,int n)
{
    
    vector<int>ans;
    //cout<<left.size()<<endl;
    int l=0;
    int r=0;
    int in=0;
    while((l<left.size())&&(r<right.size()))
    {
        if(left[l]<right[r])
        {
            
           ans.push_back(left[l]);
           l++;
            
        }
        else 
        {
           ans.push_back(right[r]);
           r++;
        }
    }
   
        while(l<left.size())
        {
            ans.push_back(left[l]);
            l++;
        }


    
    
        while(r<right.size())
        {
           ans.push_back(right[r]);
           r++;
        }


    
    return ans;
}
vector<int> mergeSort(vector<int>&arr,int n,int low,int high)
{
    if(low==high)
    {
        //cout<<arr[low]<<endl;
        vector<int>base;
        base.push_back(arr[low]);
        return base;
    }
    int mid=(low+high)/2;
    vector<int>left=mergeSort(arr,n,low,mid);
    vector<int>right=mergeSort(arr,n,mid+1,high);
    vector<int>result=merge(left,right,n);
    return result;



}
void print(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        //vector<int>arr;
        int val;
        cin>>val;
        arr.push_back(val);
    }
   vector<int>sortedArray= mergeSort(arr,n,0,n-1);
   print(sortedArray);
}