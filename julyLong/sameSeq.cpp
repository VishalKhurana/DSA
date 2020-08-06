#include <bits/stdc++.h>
using namespace std;
int sol(vector<long long int> &a, vector<long long int> &b, map<long long int, long long int> &global, map<long long int, long long int> &am, map<long long int, long long int> &bm)
{
    int count = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++)
    {

        int rem = global[a[i]] / 2 - am[a[i]];
        if (rem < 0)
        {
            int j = i;
            for (j=i; j < abs(rem); j++)
            {
                count = count + min(a[j], b[j]);
                am[a[i]]--;
                bm[a[i]]++;
            }
            i=j-1;
        }
        else
        {
            int rem1 = global[a[i]] / 2 - bm[a[i]];
        if (rem1 < 0)
        {
            int j = i;
            for (j = i; j < abs(rem); j++)
            {
                count = count + min(a[j], b[j]);
                am[a[i]]++;
                bm[a[i]]--;
            }
            i=j-1;
        }
    }
}
return count;
}

int main()
{
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        int n;
        cin >> n;
        vector<long long int> a;
        vector<long long int> b;
        map<long long int, long long int> global;
        map<long long int, long long int> am;
        map<long long int, long long int> bm;
        for (int i = 0; i < n; i++)
        {
            long long int val;
            cin >> val;
            global[val]++;
            am[val]++;
            a.push_back(val);
        }
        for (int i = 0; i < n; i++)
        {
            long long int val;
            cin >> val;
            global[val]++;
            bm[val]++;
            b.push_back(val);
        }
        map<long long int, long long int>::iterator it;
        bool isValid = true;
        for (it = global.begin(); it != global.end(); it++)
        {
            if (it->second & 1)
            {
                isValid = false;
                break;
            }
        }
        int ans = 0;
        if (isValid)
        {
            ans = sol(a, b, global, am, bm);
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}