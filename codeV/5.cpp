#include <bits/stdc++.h>
#define llt long long int
#define MOD 1000000007
using namespace std;
llt matrix[501][501];

llt min(llt first,llt second)
{
    if(first<second)
    {
        return first;
    }
    return second;
}
void antiClockRot(vector<llt> &arr, long long count)
{
    while (count--)
    {
        llt front = arr[0];
        arr.erase(arr.begin());
        arr.push_back(front);
    }
}
void clockRot(vector<llt> &arr, llt count)
{
    while (count--)
    {
        llt front = arr[arr.size() - 1];
        arr.insert(arr.begin(), front);
        arr.pop_back();
    }
}
void spiralPrintFormation(llt meiden, llt nand, vector<vector<llt>> &sol)
{
    llt i;
    llt count = 0;
    llt land = 0;
    llt pot = 0;
    llt klcount = -1;
    while (count < meiden && land < nand)
    {
        klcount++;
        pot = 0;
    
        for (i = land; i < nand; ++i)
        {
            matrix[count][i] = sol[klcount][pot];
         
            pot++;
        }
        count++;

        for (i = count; i < meiden; ++i)
        {
            matrix[i][nand - 1] = sol[klcount][pot];
        
            pot++;
        }


        nand--;

        if (count < meiden)
        {
            for (i = nand - 1; i >= land; --i)
            {
                matrix[meiden - 1][i] =sol[klcount][pot];
         
                pot++;
            }
            meiden--;
        }

        if (land < nand)
        {
            for (i = meiden- 1; i >= count; --i)
            {
                matrix[i][land] = sol[klcount][pot];
              
                pot++;
            }
            land++;
        }
    }
}
int main()
{
    llt n_check0, m_check0;
    cin >> n_check0 >> m_check0;
    llt n_check2= n_check0, m_check2 = m_check0;
    for (llt i = 0; i < n_check0; i++)
    {
        for (llt j = 0; j < m_check0; j++)
        {
            cin >> matrix[i][j];
        }
    }
    llt lrad = min(n_check0, m_check0) / 2;
    llt rotikhaa[lrad];
    llt n_check1 = n_check0, m_check1 = m_check0;
    for (llt i = 0; i < lrad; i++)
    {
        llt swaad = 2 * (n_check0 + (m_check0 - 2));
        cin >> rotikhaa[i];
        rotikhaa[i] = rotikhaa[i] % swaad;
        n_check1 -= 2;
        m_check1 -= 2;
    }
    llt i_check0, k_check0 = 0, l_check0 = 0;
    llt idx = 0;
    vector<vector<llt>>sol;
    sol.clear();
    while (k_check0 < m_check0 && l_check0 < n_check0)
    {
        vector<llt>myAns;
        myAns.clear();
        for (i_check0 = l_check0; i_check0 < n_check0; ++i_check0)
        {
            myAns.push_back(matrix[k_check0][i_check0]);
        }
        k_check0++;

        for (i_check0 = k_check0; i_check0 < m_check0; ++i_check0)
        {
            myAns.push_back(matrix[i_check0][n_check0 - 1]);
        }
        n_check0--;

        if (k_check0 < m_check0)
        {
            for (i_check0 = n_check0 - 1; i_check0 >= l_check0; --i_check0)
            {
                myAns.push_back(matrix[m_check0 - 1][i_check0]);
            }
            m_check0--;
        }

        if (l_check0 < n_check0)
        {
            for (i_check0 = m_check0 - 1; i_check0>= k_check0; --i_check0)
            {
                myAns.push_back(matrix[i_check0][l_check0]);
            }
            l_check0++;
        }
        if (idx % 2 == 0)
        {
            antiClockRot(myAns, rotikhaa[idx]);
            sol.push_back(myAns);
        }
        else
        {
            clockRot(myAns, rotikhaa[idx]);
            sol.push_back(myAns);
        }
        idx++;
    }
    //cout<<sol<<endl;
    spiralPrintFormation(m_check2, n_check2, sol);
    for (llt i = 0; i < n_check2; i++)
    {
        for (llt j = 0; j < m_check2; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout <<'\n';
    }
    return 0;
}