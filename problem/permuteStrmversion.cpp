#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printPermute(string str, int idx, vector<vector<string>>& ans) {
    if (idx == str.length()) {
        ans.push_back({str});
        return;
    }

    for (int i = idx; i < str.length(); i++) {
        swap(str[idx], str[i]);
        printPermute(str, idx+1, ans);

        // BackTracking
        swap(str[idx], str[i]);
    }
}

int main() {
    string str = "abc";
    vector<vector<string>> ans;
    printPermute(str, 0, ans);

    for (int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << endl;
        }
    }
    return 0;
}