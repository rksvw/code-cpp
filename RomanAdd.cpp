// C++ Program to Create a dictionary using
// unordered_map
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "MCMXCIV";
    // Create an empty dictionary using unordered_map
    map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        int sum = 0;
        int num1 , num2;
        for (int i = 0; i < s.length(); i++) {
            int j = i+1;
            num1 = dict[s[i]];
            if (j != s.length()) {
                num2 = dict[s[j]];
            } else {
                num2 = 0;
            }

            if (num1 < num2) {
                sum = sum - num1;
            } else {
                sum = sum + num1;
            }
        }
        cout << sum << endl;
        return 0;
}