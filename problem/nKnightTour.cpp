#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>> &grid, int row, int col, int sz, int expValue) {
    if (row < 0 || col < 0 || row >= sz || col >= sz || grid[row][col] != expValue) {
        return false;
    }

    if (expValue == sz*sz - 1) {
        return true;
    }

    // 8 possible moves
    int ans1 = isValid(grid, row-2, col+1, sz, expValue + 1);
    int ans2 = isValid(grid, row-1, col+2, sz, expValue + 1);
    int ans3 = isValid(grid, row-2, col-1, sz, expValue + 1);
    int ans4 = isValid(grid, row-1, col-2, sz, expValue + 1);
    int ans5 = isValid(grid, row+2, col-1, sz, expValue + 1);
    int ans6 = isValid(grid, row+1, col-2, sz, expValue + 1);
    int ans7 = isValid(grid, row+2, col+1, sz, expValue + 1);
    int ans8 = isValid(grid, row+1, col+2, sz, expValue + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid(vector<vector<int>> &grid) {
    return isValid(grid, 0, 0, grid.size(), 0);
}

int main() {
    return 0;
}