#include <bits/stdc++.h>
using namespace std;
void computeLPS(vector<int> &lps, string &pattern, int size)
{
    int len = 0;
    int i = 1;
    while (i < size)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    //    for(int i=0;i<size;i++)
    //    {
    //        cout<lps
    //    }
}
bool KMP(string str, string pattern, vector<int> &lps)
{
    int i = 0;
    int j = 0;
    while (i < str.size())
    {
        if (pattern[j] == str[i])
        {
            i++;
            j++;
        }
        if (j == pattern.size())
        {
            cout << i - j << endl;
            j = lps[j - 1];
            // return true;
        }
        else if (i < str.size() && pattern[j] != str[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return false;
}
// bool rotateString(string A, string B) {
//     if(A.size()==0&&B.size()==0)
//     {
//         return true;
//     }
//     if(A.size()!=B.size())
//     {
//         return false;
//     }
//     string A1=A.append(A);
//     cout<<A1<<endl;
//     int size=B.size();
//     vector<int>lps(size,0);
//     computeLPS(lps,B,size);
//     cout<<lps[0]<<endl;
//     bool ans=KMP(A1,B,lps);
//     return ans;

// }
int main()
{

    string s = "abbbab";
    string str = "aaabbbabnbabbbab";
    int size = s.size();
    vector<int> lps(size, 0);
    computeLPS(lps, s, size);
    for (int i = 0; i < lps.size(); i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
    bool ans = KMP(str, s, lps);

    cout << ans << endl;
    return 0;
}
