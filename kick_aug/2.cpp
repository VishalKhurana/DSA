#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        map<long long int,long long int>time;
        map<long long int,long long int>reps;
        map<long long int,long long int>deti;
        long long int max_time=0;
        long long int tim=0;
        int idx=1;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            long long int a,b;
            cin>>a>>b;
            tim=tim+a;
            time[idx]=b;
            reps[idx]=tim;
            deti[idx]=a;
            idx++;


        }
        long long int ans=tim;
        int count=0;
        idx=1;
        int rm=0;
        bool flag=false;
        while(1)
        {
            if(reps.size()==0)
            {
               break;

            }
            if(count==n+2)
            {
                flag=true;
                break;
            }
         if(idx==n+1)
         {
             idx=1;
         }
            if(reps.count(idx)==0)
            {
                idx++;
                continue;
            }
            //cout<<(tim-reps[idx])<<endl;
            if((tim-reps[idx])>=(time[idx]))
            {

                count++;
                tim=tim+deti[idx];
                ans=ans+deti[idx];
                reps[idx]=tim;
                idx++;
            }
            else
            {
                //cout<<"in"<<endl;
                rm++;
                reps.erase(idx);
                count=0;
                idx++;
            }
            

        }
        if(flag)
        {
            cout<<"Case"<<" "<<"#"<<p+1<<":"<<" "<<rm<<" "<<"INDEFINITELY"<<endl;
        }
        else
        {
            if(rm==n)
            {
                rm=0;
            }
             cout<<"Case"<<" "<<"#"<<p+1<<":"<<" "<<rm<<" "<<ans<<endl;
        }
        


    }
    return 0;
}