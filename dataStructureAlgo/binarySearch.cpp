#include<iostream>
#include<vector>
using namespace std;

int binSearchIterate(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> vec = { 1, 3, 5, 7, 9, 11, 14, 16, 19, 20};

    cout << binSearchIterate(vec, 12) << endl;
    return 0;
}