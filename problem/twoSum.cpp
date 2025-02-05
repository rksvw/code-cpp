#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& A, int target) {
    int start = 0, end = A.size() - 1;
    vector<int> ans;

    while(start < end) {
        int sum = A[start] + A[end];

        if (sum == target) {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
        else if (sum > target) {
            if (A[start + 1] + A[end] < sum) {
                start++;
            }
            else {
                end--;
            }
        }
        else {
            if (A[start + 1] + A[end] > sum) {
                start++;
            }
            else {
                end--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> Arr = {3,2,4};
    vector<int> ans;
    ans = twoSum(Arr, 9);

   for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}