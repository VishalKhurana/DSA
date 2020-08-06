#include<bits/stdc++.h>
using namespace std;
vector<int>insertionSort(vector<int>&arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    vector<int>sortedArray=insertionSort(arr,n);
    print(sortedArray);
}