#include<iostream>
#include<vector>
using namespace std;

int binSearch(vector<int>& nums, int target, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            return binSearch(nums, target, start, mid - 1);
        } else {
            return binSearch(nums, target, mid + 1, end);
        }
    }
    return -1;
}

int main() {
    vector<int> vec = { 1, 3, 5, 7, 9, 11, 14, 16, 19, 20};

    cout << binSearch(vec, 100, 0, vec.size() - 1) << endl;
    return 0;
}