#include<iostream>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int z=n/k;
        if(z==m) {
            cout<<m<<endl;
            continue;
        }else if(z>m){
            cout<<m<<endl;
            continue;
        }else{
            int cards_remaining=m-z;
            int pep=k-1;
            int cards_divided=cards_remaining/pep;
            if(pep>cards_remaining) cout<<z-1<<endl;
            else if(cards_remaining%pep==0) cout<<z-cards_divided<<endl;
            else cout<<z-cards_divided-1<<endl;
        }
    }
}