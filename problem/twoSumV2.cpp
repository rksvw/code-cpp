#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& A, int target) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < A.size(); i++) {
        int first = A[i];
        int sec = target - first;

        if (m.find(sec) != m.end()) {
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[first] = i;
    }
    return ans;
}

int main() {
    vector<int> A = {3, 2, 4};
    vector<int> ans = twoSum(A, 6);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << endl;
    }
    cout << "\n";
    return 0;
}