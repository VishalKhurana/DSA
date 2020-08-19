#include<bits/stdc++.h>
using namespace std;
int Search(int low, int high, int N) 
{ 
  
    if (low <= high) { 

        int mid = (low + high) / 2; 
  
        if ((mid * mid <= N) 
            && ((mid + 1) * (mid + 1) > N)) { 
            return mid; 
        } 
  
        else if (mid * mid < N) { 
            return Search(mid + 1, high, N); 
        } 
        else { 
            return Search(low, mid - 1, N); 
        } 
    } 
    return low; 
} 
int main()
{
    int n;
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n));
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            if(c=='D')
            {
                count++;
            }
            board[i][j]=c;
        }
    }
    int ans=Search(0,count,count);
    // int temp_ans=floor(sqrt(count));
    cout<<ans<<endl;
}