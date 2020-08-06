#include<bits/stdc++.h>
using namespace std;
int GetNumWays(string s) {
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  int n = s.length();
  // right[i] == n_unique_char for s[i .. n-1]
  vector<int> right(n);
  vector<bool> seen(128); 
  for (int i = n-1; i >= 0; --i) {
    if (i != n-1) right[i] = right[i+1];
    if (!seen[s[i]]) {
      seen[s[i]] = true;
      ++right[i];
    }
  }
  for(int i=0;i<right.size();i++)
  {
      cout<<right[i]<<" ";
  }
  cout<<endl;

  fill(seen.begin(), seen.end(), false);
  // left tracks n_unique_char for s[0 .. i]
  int n_ways = 0, left = 0;
  for (int i = 0; i < n-1; ++i) {
    if (!seen[s[i]]) {
      seen[s[i]] = true;
      ++left;
    }
    cout<<left<<" "<<right[i+1]<<endl;
    n_ways += left == right[i+1];
  }
  return n_ways;
}

int main() {
  int ans=GetNumWays("aabaca");
  cout<<ans<<endl;
//   assert(0 == GetNumWays("bac"));
//   assert(2 == GetNumWays("ababa"));
}