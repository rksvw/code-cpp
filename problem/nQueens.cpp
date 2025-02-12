#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int num)
{
    // Check Horizontal
    for (int j = 0; j < num; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // Check Vertical
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Left Diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Right Diagonal
    for (int i = row, j = col; i >= 0 && j < num; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board, int row, int num, vector<vector<string>> &ans)
{
    if (row == num)
    {
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < num; j++)
    {
        if (isSafe(board, row, j, num))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1, num, ans);

            // Backtracking
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}

int main()
{
    vector<vector<string>> queens;
    queens = solveNQueens(4);

    for (int i = 0; i < queens.size(); i++)
    {
        for (int j = 0; j < queens.size(); j++)
        {
            cout << queens[i][j] << endl;
        }
    }
    return 0;
}