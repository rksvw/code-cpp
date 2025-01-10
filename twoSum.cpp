#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int st = 0;
    int en = nums.size() - 1;
    vector<int> ans;

    // sort
    sort(nums.begin(), nums.end());

    while (st < en) {
        int chkSum = nums[st] + nums[en];
        if (chkSum < target) {
            st++;
        } else if (chkSum > target) {
            en--;
        } else {
            ans.push_back(st);
            ans.push_back(en);
            return ans;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}