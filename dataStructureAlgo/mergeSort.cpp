#include<iostream>
#include<vector>
using namespace std;
static int count = 0;
void merge(vector<int> &nums, int st, int mid, int en) {
    vector<int> temp;
    int i = st, j = mid+1;
    // Ignore bottom line loop
    cout << "\n=============" << count << "=============\n" << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    count++;
    // Ignore top level loop

    // Right Half
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

    // Right Half
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    // Left Half
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
    // Run until the start is less than end
    if (st < en) {
        // mid of vector
        int mid = st + (en - st) / 2;

        // Right Half Recursion Call
        mergeSort(nums, st, mid);

        // Left Half Recursion Call
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