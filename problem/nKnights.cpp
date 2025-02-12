#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int num)
{

    const int knightMoves[8][2] = {
        {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {1, -2}, {2, -1}};

    for (auto &moves : knightMoves)
    {
        int newRow = row + moves[0];
        int newCol = col + moves[1];
        if (newRow >= 0 && newRow < num && newCol >= 0 && newCol < num)
        {
            if (board[newRow][newCol] == 'K')
            {
                return false;
            }
        }
    }

    return true;
}

void nKnight(vector<string> &board, int row, int num, vector<vector<string>> &ans)
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
            board[row][j] = 'K';
            nKnight(board, row + 1, num, ans);

            // Backtracking
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNKnights(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nKnight(board, 0, n, ans);
    return ans;
}

int main()
{
    vector<vector<string>> knight;
    knight = solveNKnights(4);

    for (const auto &solution : knight)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl; // Separate each solution with an empty line
    }
    return 0;
}