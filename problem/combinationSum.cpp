#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<vector<int>> s;
void helper(vector<int> &nums, int idx, vector<int> &combine, vector<vector<int>> &ans, int tar) {
    // size of array
    int sz = nums.size();
    // Base Case 0
    if (idx == sz || tar < 0) {
        return ;
    }
    // Base Case 1
    if (tar == 0) {
        if (s.find(combine) == s.end()) {
            ans.push_back(combine);
            s.insert(combine);
        }
        return ;
    }
    combine.push_back(nums[idx]);
    // Include Single
    helper(nums, idx+1, combine, ans, tar - nums[idx]);
    // Include Multiple
    helper(nums, idx, combine, ans, tar - nums[idx]);
    // Backtrack
    combine.pop_back();
    // Exclude Single
    helper(nums, idx+1, combine, ans, tar);
}

vector<vector<int>> combinationSum(vector<int> &nums, int tar) {
    vector<vector<int>> ans;
    vector<int> combine;
    helper(nums, 0, combine, ans, tar);
    return ans;
}

int main() {
    vector<int> nums = {2, 3, 5};
    int tar = 8;
    vector<vector<int>> ans;
    ans = combinationSum(nums, tar);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}