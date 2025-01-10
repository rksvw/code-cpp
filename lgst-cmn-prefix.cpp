#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int count = 0;
    string word = strs[0];
    if (word == "") {
        return {""};
    }
    string str = "";

    for (int i = 1; i < strs.size(); i++) {
        for (int j = 0; j < word.size(); j++) {
            if ((j == strs[i].size() && j == word.size()) || (strs[i][j] != word[j])) {
                break;
            }
            str = str + strs[i][j];
        }
        if (i == 0) {
            i++;
        }
        word = str;
        str = "";
    }
    return word;
}

int main() {
    vector<string> str = {""};

    // cout << str[1].size() << endl;
    cout << longestCommonPrefix(str) << endl;
    return 0;
}