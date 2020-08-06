// #include<bits/stdc++.h>
// using namespace std;
// void counter()
// {
//     static int count=0;
//     cout<<count+1<<" ";
//     count++;
// }
// int main()
// {
//     int n;
//     cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        counter();
//    }
// }
#include<iostream> 
using namespace std; 
  
class GfG 
{ 
   public: 
     static int i; 
      
     GfG() 
     { 
        // Do nothing 
     }; 
}; 
int GfG ::i=5;
  
int main() 
{ 
  GfG obj1; 
  GfG obj2; 
//   obj1.i =2; 
//   obj2.i = 3; 
    
  // prints value of i 
  cout << obj1.i<<" "<<obj2.i;    
} 