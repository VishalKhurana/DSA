#include <bits/stdc++.h>
using namespace std;
vector<int> sol(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(0);
    int i = 1;
    vector<int>ans;
    while (!st.empty())
    {
        while (!st.empty() && arr[i] > st.top())
        {
            st.pop();
            // cout << arr[i] << " ";
            ans.push_back(arr[i]);
        }
        if(i==n-1)
        {
            break;
        }
        st.push(i);
        i++;
    }
    ans.push_back(-1);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    vector<int> ans = sol(arr, n);
    for(int i=0;i<ans.size();i++)
     {
         cout<<ans[i]<<" ";
     }

    return 0;
}