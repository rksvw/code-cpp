#include<iostream>
#include<string>
using namespace std;

int sumOfRom(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'M')
        {
            res = res + 1000;
        }
        else if (s[i] == 'D')
        {
            res = res + 500;
        }
        else if (s[i] == 'C') {
            if (i + 1 < s.size() && s[i + 1] == 'D') {
                res = res + 400;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'M') {
                res = res + 900;
                i++;
            }
        }
        else if (s[i] == 'L') {
           res = res + 50;
        }
        else if (s[i] == 'X') {
            if (i + 1 < s.size() && s[i + 1] == 'L') {
                res = res + 40;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'C') {
                res = res + 90;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'D') {
                res = res + 490;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'M') {
                res = res + 990;
                i++;
            }
        }
        else if (s[i] == 'V') {
            res = res + 5;
        }
        else if (s[i] == 'I') {
            if (i + 1 < s.size() && s[i + 1] == 'V') {
                res = res + 4;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'X') {
                res = res + 9;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'L') {
                res = res + 49;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'C') {
                res = res + 99;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'D') {
                res = res + 499;
                i++;
            }
            else if (i + 1 < s.size() && s[i + 1] == 'M') {
                res = res + 999;
                i++;
            }
        }
    }

    return res;
}


int main() {
    string str = "MCMXCIV";

    cout << str << endl;
    int totalSum = sumOfRom(str);
    cout << "Sum of Roman is " << totalSum << endl;
    return 0;
}