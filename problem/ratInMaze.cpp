#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &vis)
{
    int n = mat.size();
    if (row >= n || row < 0 || col >= n || col < 0 || mat[row][col] == 0 || vis[row][col] == true)
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    vis[row][col] = true;

    // Up
    helper(mat, row - 1, col, path + "U", ans, vis);
    // Right
    helper(mat, row, col + 1, path + "R", ans, vis);
    // Down
    helper(mat, row + 1, col, path + "D", ans, vis);
    // Left
    helper(mat, row, col - 1, path + "L", ans, vis);

    vis[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    string path = "";
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    helper(mat, 0, 0, path, ans, vis);
    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> path;
    path = findPath(mat);

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << endl;
    }

    return 0;
}