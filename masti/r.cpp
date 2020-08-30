#include<iostream>
#include<vector>
using namespace  std;
int main()
{
    vector<int>arr={1,1,2,4};
    int i=0;
    int j=arr.size()-1;
    int count=0;
    while(i<j)
    {
        if(arr[i]*arr[i]<=4)
        {
            count++;
        }
        
        if(arr[i]*arr[j]<=4)
        {
            count=count+(j-i)*2;
            i++;
            
     }
        else
        {
            if(arr[j]*arr[j]<=4)
            {
                count++;
            }
            j--;
        }
        
        
    }
    cout<<count<<endl;
    return 0;
}