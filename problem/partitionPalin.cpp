#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindrome(string str) {
    string str2 = str;
    reverse(str2.begin(), str2.end());
    return str2  == str;
}

void getAllPartition(string str, vector<vector<string>> &ans, vector<string> &partit) {
    if (str.size() == 0) {
        ans.push_back(partit);
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        string parts = str.substr(0, i+1);

        if (isPalindrome(parts)) {
            partit.push_back(parts);

            getAllPartition(str.substr(i+1), ans, partit);

            partit.pop_back();
        }
    }
}

vector<vector<string>> palindromePartition(string str) {
    vector<vector<string>> ans;
    vector<string> partition;

    getAllPartition(str, ans, partition);
    return ans;
}

int main() {

    string str = "abcaba";
    vector<vector<string>> ans;
    ans = palindromePartition(str);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0 ; j < ans[i].size(); j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}