#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n=s.size();
    string ans="";
    for(int i=n-1;i>=0;i--)
    {
        ans=ans+s[i];
    }
    cout<<ans<<endl;
	return 0;
}