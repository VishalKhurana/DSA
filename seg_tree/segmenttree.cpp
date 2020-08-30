#include <bits/stdc++.h>
using namespace std;

vector<int> arr(100001);
vector<int> st(400001);

void buildTree(int idx, int s, int e)
{
    if (s == e)
    {
        st[idx] = arr[s];
        return;
    }
    int mid = s + (e - s) / 2;
    buildTree(2 * idx, s, mid);
    buildTree(2 * idx + 1, mid + 1, e);

    st[idx] = min(st[2 * idx], st[2 * idx + 1]);
}
int query(int idx, int s, int e, int qs, int qe)
{
    if (qe < s || qs > e)
    {
        return INT_MAX;
    }
    if(s>=qs&&e<=qe)
    {
        return st[idx];
    }
    int mid = s + (e - s) / 2;
    int l = query(2 * idx, s, mid, qs, qe);
    int r = query(2 * idx + 1, mid + 1, e, qs, qe);

    return min(l, r);
}
void update(int idx, int s, int e, int q)
{
    if (s == e)
    {
        st[idx] = arr[s];
        return;
    }
    int mid = s + (e - s) / 2;
    if (q <= mid)
    {
        update(2 * idx, s, mid, q);
    }
    else
    {
        update(2 * idx + 1, mid + 1, e, q);
    }

    st[idx] = min(st[2 * idx], st[2 * idx + 1]);
}
int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        arr[i]=val;
    }

    buildTree(1, 1, n);
    for(int i=1;i<=4*n;i++)
    {
        cout<<st[i]<<" ";

    }
    cout<<endl;
    
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;

        if (c == 'Q')
        {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 1, n, l, r );
            cout << ans << endl;
        }
        else
        {
            int idx,val;
            cin>>idx>>val;
            arr[idx]=val;
            update(1,1,n,idx);
        }
        
    }
}