#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

lli mod = 1000000007;

int n;
char a[200000 + 10];
lli dp[200000 + 10][9];

lli solve(int pos, int rem)
{
    if (pos == n)
        return (rem == 0);

    if (dp[pos][rem] != -1)
        return dp[pos][rem];

    dp[pos][rem] = 0;
    if (pos + 1 <= n)
        dp[pos][rem] = solve(pos + 1, (rem * 10 + (a[pos] - '0')) % 8);
    if (pos + 1 <= n)
        dp[pos][rem] += solve(pos + 1, rem);
    dp[pos][rem] %= mod;

    return dp[pos][rem];
}

int main(void)
{
    memset(dp, -1, sizeof dp);

    cin >> n;
    cin >> a;

    lli ans = solve(0, 0);

    cout << (ans - 1 + mod) % mod << endl;
    return 0;
}