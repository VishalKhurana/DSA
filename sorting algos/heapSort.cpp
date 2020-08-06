#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr,int n,int i)
{

   int left=2*i+1;
   int right=2*i+2;
   int largest=i;
   if((left<n)&&arr[largest]<arr[left])
   {
       largest=left;

   }
   if((right<n)&&(arr[largest]<arr[right]))
   {
       largest=right;

   }

   if(largest!=i)
   {
       swap(arr[i],arr[largest]);
       heapify(arr,n,largest);
   }


}
vector<int>heapSort(vector<int>&arr,int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    return arr;
}
void print(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    vector<int>sortedArray=heapSort(arr,n);
    print(sortedArray);
}