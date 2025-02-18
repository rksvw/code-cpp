#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &nums, int st, int mid, int en) {
    vector<int> temp;
    int i = st;
    int j = mid+1;
    int invCount = 0;

    while(i <= mid && j <= en) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }
    cout << " Inv Count : " << invCount << endl;

    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= en) {
        temp.push_back(nums[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        nums[idx + st] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int> &nums, int st, int en) {
    if (st < en) {
        int mid = st + (en - st) / 2;
        int leftCount = mergeSort(nums, st, mid);
        cout << " Left Count : " << leftCount << endl;
        int rightCount = mergeSort(nums, mid+1, en);
        cout << " Right Count : " << rightCount << endl;
        int invCount = merge(nums, st, mid, en);
        cout << " Merge Count : " << invCount << endl;
        cout << " Add (left + right + inv) : " << leftCount + rightCount + invCountd << endl;
        return leftCount + rightCount + invCount;
    }

    return 0;
}

int main() {
    vector<int> nums = {6, 3, 5, 2, 7}; //{1, 3, 5, 10, 2, 6, 8, 9};
    int invCount = mergeSort(nums, 0, nums.size() - 1);
    cout << "Inversion Count : " << invCount << endl;
    return 0;
}