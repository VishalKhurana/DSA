#include<bits/stdc++.h>
using namespace std;

    void simplifiedFractions(int n) {
        int num=1;
        int deno=2;
        for(int num=1;num<n;num++)
        {
            for(int deno=num+1;deno<num;deno++)
            {
                cout<<num<<" "<<deno<<endl;
            }
        }
        vector<string>arr;
        //return arr;
        
        
    }
int main()
{
    simplifiedFractions(4);
    return 0;
}