#include<bits/stdc++.h>
using namespace std;
int findPivot(vector<int>&arr,int left,int right)
{
    int pivot=arr[(left+right)/2];
    while(left<=right)
    {
        while(arr[left]<pivot)
        {
            left++;
        }
        while(arr[right]>pivot)
        {
            right--;
        }
        if(left<=right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    return left;


}
void quickSort(vector<int>&arr,int n,int left,int right)
{
    int index=findPivot(arr,left,right);
    if(left<index-1)
    {
        quickSort(arr,n,left,index-1);

    }
    if(right>index)
    {
        quickSort(arr,n,index,right);
    }

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
    quickSort(arr,n,0,n-1);
    print(arr);
}