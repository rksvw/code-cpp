#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int st, int mid, int en) {
    vector<int> temp;
    int i = st, j = mid+1;

    // Sort the vector using 2 pointer approach
    while(i <= mid && j <= en) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    // Put the Sort value at right half of Temp Array
    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    // Put the Sort value at left half of Temp Array
    while(j <= en) {
        temp.push_back(nums[j]);
        j++;
    }

    // Copy the sorted Vector to Original Vector
    for (int idx = 0; idx < temp.size(); idx++) {
        nums[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int> &nums, int st, int en) {
    if(st < en) {
        int mid = st + (en - st) /2;

        // Right Half Recursion Call
        mergeSort(nums, st, mid);

        // Left half Recursion call
        mergeSort(nums, mid+1, en);

        // Merge the two half
        merge(nums, st, mid, en);
    }
}


int main() {
    vector<int> nums = {12, 31, 35, 8, 32, 17};

    mergeSort(nums,0, nums.size());

    cout << "==========================" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}