#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &mat, int row, int col, string path, vector<string> &ans) {
    int sz = mat.size();
    if (row < 0 || col < 0 || row >= sz || col >= sz || mat[row][col] == 0 || mat[row][col] == -1) {
        return ;
    }

    if (row == sz-1 && col == sz-1) {
        ans.push_back(path);
        return ;
    }

    mat[row][col] = -1;
    // Up
    helper(mat, row-1, col, path+"U", ans);
    // Right
    helper(mat, row, col+1, path+"R", ans);
    // Down
    helper(mat, row+1, col, path+"D", ans);
    // Left
    helper(mat, row, col-1, path+"L", ans);

    mat[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    string path = "";

    helper(mat, 0, 0, path, ans);
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1,}
    };

    vector<string> ans;
    ans = findPath(mat);

    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << endl;
    // }

    for (auto &path : ans) {
        cout << path << endl;
    }
    return 0;
}