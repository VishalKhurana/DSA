#include<bits/stdc++.h>
using namespace std;
vector<int>selectionSort(vector<int>&arr,int n)
{
    int min_=INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
           

        }
      
        swap(arr[minIndex],arr[i]);
        
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
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    vector<int>sortedArray=selectionSort(arr,n);
    print(arr);

}