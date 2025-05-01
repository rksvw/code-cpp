#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {0,4};
    int save = nums[0];
    int saveIdx = 0;
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == save) {
            nums[i] = 0;
        } else{
            save = nums[i];
            saveIdx = saveIdx + 1;
            nums[i] = 0;
            nums[saveIdx] = save;
            count++;
        }
    }

    while(nums.size() != count) {
        nums.pop_back();
    }

    cout << "Save Idx " << saveIdx << endl;
    cout << "Count Idx " << count << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}

