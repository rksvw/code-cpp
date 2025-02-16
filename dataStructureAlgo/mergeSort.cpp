#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int st, int mid, int en) {
    vector<int> temp;
    int i = st, j = mid+1;

    while(i <= mid && j <= en) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    // Left Half
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= en)
    {
        temp.push_back(nums[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        nums[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int> &nums, int st, int en) {
    if (st < en) {
        int mid = st + (en - st) / 2;

        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, en);

        merge(nums, st, mid, en);
    }
}

int main() {
    vector<int> nums = {12, 31, 35, 8, 32, 17};

    mergeSort(nums,0, nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}