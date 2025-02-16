#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string str) {
    string str2 = str;
    reverse(str2.begin(),str2.end());

    return str == str2;
}

void getAllPartition(string str, vector<string> &partition, vector<vector<string>> &ans) {
    if (str.size() == 0) {
        ans.push_back(partition);
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        // cut the parts of string
        string parts = str.substr(0, i+1);
        // Check the cut partitions are palindrome
        if (isPalindrome(parts)) {
            // Add -> partitions
            partition.push_back(parts);
            // Recursion
            getAllPartition(str.substr(i+1), partition, ans);
            // Backtracking
            partition.pop_back();
        }
    }
}

vector<vector<string>> palindromePartiton(string str) {
    vector<vector<string>> ans;
    vector<string> partition;

    getAllPartition(str, partition, ans);
    return ans;
}

int main() {
    string str = "aab";
    vector<vector<string>> palPart;
    palPart = palindromePartiton(str);

    for (int i = 0; i < palPart.size(); i++) {
        for (int j = 0; j < palPart[i].size(); j++) {
            cout << palPart[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}