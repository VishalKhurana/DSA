#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int zero=0,one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero++;
            else one++;
        }
        if(zero==0 || one==0){
            cout<<s<<endl;
            continue;
        }
        int cnt=2*k;
        if(zero==cnt && one==cnt){
            string ans="0";
            int num=1;
            while(num<=n){
            for(int m=1;m<=k;m++) ans+="1";
            for(int m=1;m<=k;m++) ans+="0";
            num+=(2*k);    
            }
            cout<<(ans.substr(0,n))<<endl;
        }else{
            cout<<"IMPOSSIBLE\n";
        }
    }
}