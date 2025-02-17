#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums, int st, int en) {
    // taking the last element as pivot
    int pivot = nums[en];
    int idx = st -1;
    int end = en - 1;

    // placing the pivot element at its correct position
    for (int i = st; i <= end; i++) {
        if (nums[i] <= pivot) {
            idx++;
            swap(nums[idx], nums[i]);
        }
    }

    // swaping the pivot element with the element at idx + 1
    idx++;
    swap(nums[en], nums[idx]);
    return idx;
}

void quickSort(vector<int> &nums, int st, int en) {
    if (st < en) {
        // partitioning the pivot index and then sorting the left and right subarrays
        int pivotIdx = partition(nums, st, en);

        // Left subarray
        quickSort(nums, st, pivotIdx - 1);

        // Right subarray
        quickSort(nums, pivotIdx +1, en);
    }
}

int main() {
    vector<int> nums = {8, 2, 1, 5, 4, 6,3};

    quickSort(nums, 0, nums.size() - 1);
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}