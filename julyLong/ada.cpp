#include <bits/stdc++.h>
using namespace std;
void sol(int n)
{
    if (n == 64)
    {
        vector<vector<char>> base(8, vector<char>(8, '.'));
        base[0][0] = 'O';
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << base[i][j];
            }
            cout << endl;
        }
        return;
    }

    int row = n / 8;
    int col = n % 8;
    vector<vector<char>> board(8, vector<char>(8, 'X'));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            board[i][j] = '.';
        }
    }
    for (int i = 0; i < col; i++)
    {
        board[row][i] = '.';
    }
    board[0][0] = 'O';
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        int n;
        cin >> n;
        sol(n);
        // cout << endl;
    }
}