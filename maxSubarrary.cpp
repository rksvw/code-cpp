#include<iostream>
#include<vector>
using namespace std;

int maxLength(vector<int>& nums) {
        int len = nums.size();
        if (prod(nums, len) == findLCM(nums, len) * findGDC(nums, len)) {
            return prod(nums, len);
        }
}

int prod(vector<int>& nums, int sz) {
        int product = 1;
        for (int i = 0; i < sz; i++) {
            product *= nums[i];
        }

        return product;
}

int findLCM(vector<int>& nums, int sz) {
        int ans = nums[0];
        for (int i = 1; i < sz; i++) {
            ans = ((nums[i] * ans) / gcd(nums[i], ans));
        }

        return ans;
}


int findGDC(vector<int>& nums, int sz) {
        int result = nums[0];
        for (int i = 1; i < sz; i++) {
            result = gcd(nums[i], result);
            if (result == 1) {
                return 1;
            }
        }

        return result;
}

int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }

        return gcd(b%a, a);
    }

int main() {
    vector<int> nums = {1, 2, 1, 2, 1, 1, 1};
    cout << maxLength(nums);
}