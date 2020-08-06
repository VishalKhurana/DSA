#include<bits/stdc++.h>
using namespace std;
vector<int>bubbleSort(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }

        }
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
    vector<int>sortedArray=bubbleSort(arr,n);
    print(sortedArray);
}