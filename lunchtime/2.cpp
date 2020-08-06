#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <map> 
#include <vector>
#include <queue>
#include <stack>
#include <set>
 
using namespace std;
      
typedef long long ll;
typedef string ss;
  
#define pb push_back
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define sec second
#define fst first
#define pii pair < int, int >
  
const int N = 1e5 + 5, INF = int(1e9), mod = int(1e9) + 9, base = 10;
 
int n, a[N], q, w[N], res[N];
 
int main(){
	cin >> q;
	while(q--){
		cin >> n;
		memset(w, 0, sizeof(w));
		bool cond = 1;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(a[i] < i or a[i] < a[i - 1]){
				cond = 0;
			}
			w[a[i]] = 1;
		}
		if(!cond){
			cout << -1 << "\n";
			continue;
		}
		queue < int > que;
		for(int i = 1; i <= n; i++){
			if(w[i] != 1){
				que.push(i);
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] > a[i - 1]){
				res[i] = a[i];
			}
			else if(a[i] == a[i - 1]){
				res[i] = que.front();
				que.pop();
			}
		}
		for(int i = 1; i <= n; i++){
			cout << res[i] << " ";
		}
		cout << "\n";
	}
}