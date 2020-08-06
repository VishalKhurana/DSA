#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

bool rec(vi &arr,int n,int i){
    if(i==n-2){
        if(arr[i]==1) return false;
        else return true;
    }
    if(i==n-1) return true;

    bool res=false;
    if(arr[i]!=1 && !res){
        int temp=arr[i];
        arr[i]=1;
        res=!rec(arr,n,i);
        arr[i]=temp;
    }
    if(!res) res=!rec(arr,n,i+1);
    return res;
}

void solve(){
    int n;
    scanf("%d",&n);
    vi arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==1) {cout<<"First"<<endl; return;}
    if(n==2){
        if(arr[0]!=1){ cout<<"First"<<endl; return;}
        else {cout<<"Second"<<endl; return;}
    }
    if(rec(arr,n,0)) {cout<<"First"<<endl; return;}
    else {cout<<"Second"<<endl; return;}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}