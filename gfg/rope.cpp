// #include<bits/stdc++.h>
// #define mod 1000000007;
// using namespace std;
// int sol(int n)
// {
//     vector<int>dp(n+1,0);
//     dp[1]=1;
//     dp[2]=2;
//     for(int i=3;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+i;
//     }
//     return dp[n];
//     }
// int main()
// {
//     int t;
//     cin>>t;
//     for(int p=0;p<t;p++)
//     {
//         int n;
//         cin>>n;
//         int ans=sol(n);
//         cout<<ans<<endl;

//     }
//     return 0;
// }
 
// to divide circle using 
// N non-intersecting chords. 
#include <bits/stdc++.h> 
using namespace std; 
  
int chordCnt( int A){ 
  
    // n = no of points required 
    int n = 2 * A; 
      
    // dp array containing the sum 
    int dpArray[n + 1]={ 0 }; 
    dpArray[0] = 1; 
    dpArray[2] = 1; 
    for (int i=4;i<=n;i+=2){ 
        for (int j=0;j<i-1;j+=2){  
              
          dpArray[i] += 
            (dpArray[j]*dpArray[i-2-j]); 
        } 
    }  
  
    // returning the required number 
    return dpArray[n]; 
} 
// Driver function 
int main() 
{ 
  
  int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int ans=chordCnt(n);
        cout<<ans<<endl;

    }
    return 0;
   
} 
  