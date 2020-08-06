#include<bits/stdc++.h>
using namespace std;
void generateMatrix(int n)
{
    int odd=1,even=2;
    bool odd_=true,even_=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(odd_)
            {
            cout<<odd<<" ";
            odd+=2;
            odd_=false;
            even_=true;
            }
            else
            {
                cout<<even<<" ";
                even+=2;
            odd_=true;
            even_=false;
            }
            
        }
        if(n%2==0)
        {
        odd_=!odd_;
        even_=!even_;
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        generateMatrix(n);
        
    }
    return 0;
}