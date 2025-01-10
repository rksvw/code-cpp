#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string str1 = strs[0];
    int n = strs.size();

    for (int i = 1; i < n; i++) {
        int str1_size = str1.size();
        string str2 = strs[i];
        int str2_size = str2.size();

        if (str1_size > str2_size) {
            str1 = str1.substr(0, str2_size); // here goes the string of size str2
        } else if (str2_size > str1_size) {
            str2 = str2.substr(0, str1_size); // here goes the string of size str1
        }

        while ((str1 != str2) && (str1.length() == str2.length())) {
            str1.pop_back();
            str2.pop_back();
        }

        if (str1.empty()) {
            return "";
        }
    }
    return str1;
}

int main() {
    vector<string> str = {"a", "ab", "abc"};

    // cout << str[1].size() << endl;
    cout << longestCommonPrefix(str) << endl;
    return 0;
}