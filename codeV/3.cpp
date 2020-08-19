#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long  max(long long first, long long second)
{
    if(first>second)
    {
        return first;
    }
    return second;
}

int sol(vector<int>&arr, int n_check, int breadth, int height)
{
    long long  myA = 0;

    stack<int>myStans;

    myStans.push(-1);

    int count = 0;

    while (count < n_check)
    {
        while (myStans.top() != -1 && arr[myStans.top()] >= arr[count])
        {
            //cout<<count<<endl;
            int test = myStans.top();

            myStans.pop();

            long long cvar_ = arr[test];

            long long  firstArea = cvar_ * (count - myStans.top() - 1);

            myA= (max(myA,firstArea)) % MOD;
        }
        myStans.push(count);
        count++;
    }

    while (myStans.top() != -1)
    {
        int test = myStans.top();

        myStans.pop();

        long long cvar_ = arr[test];

        long long firstArea = cvar_ * (count - myStans.top() - 1);

        //cout<<firstArea<<endl;
        myA = (max(myA,firstArea)) % MOD;
    }


    int ans__=(int)(myA * breadth * height) % MOD;

    return ans__;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n_check;
    cin >>n_check;
    int breadth, height;
    cin >> breadth >> height;
    vector<int>arr(n_check);
    long long int mYSum = 0;
    for (int i = 0; i <n_check; i++)
    {
        cin >> arr[i];
        mYSum = mYSum + arr[i];
    }
    mYSum = mYSum * breadth * height;
    int ans = sol(arr, n_check, breadth, height);
    ans = (mYSum - ans) % MOD;
    cout << ans << endl;
    return 0;
}