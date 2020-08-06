#include<bits/stdc++.h>
using namespace std;
int main()
{
    time_t start,end;
    time(&start);
    int32_t a=5;
    int count=0;

    for(int i=0;i<32;i++)
    {
        if(a==0)
        {
            break;
        }
            if(a&1==1)
            {
                count++;
            }
            a>>=1;

    }
    time(&end);
    double time_taken=double(end-start);
    cout<<time_taken<<endl;
    cout<<count<<endl;
    return 0;
}