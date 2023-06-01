#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &lowerD, vector<int> &row, vector<int> &upperD, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int r = 0; r < n; r++)
    {
        if (lowerD[r + col] == 0 && upperD[n - 1 + col - r] == 0 && row[r] == 0)
        {
            board[r][col] = 'Q';
            lowerD[r + col] = 1;
            upperD[n - 1 + col - r] = 1;
            row[r] = 1;
            solve(col + 1, board, ans, lowerD, row, upperD, n);
            board[r][col] = '.';
            lowerD[r + col] = 0;
            upperD[n - 1 + col - r] = 0;
            row[r] = 0;
        }
    }
}

vector<vector<string>> nq(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> lowerD(2 * n - 1, 0);
    vector<int> row(n, 0);
    vector<int> upperD(2 * n - 1, 0);
    solve(0, board, ans, lowerD, row, upperD, n);
    return ans;
}
int main()
{
    int n;
    cout << "Enter n." << endl;
    cin >> n;
    vector<vector<string>> nqueen;
    nqueen = nq(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nqueen[i][j] << endl;
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}