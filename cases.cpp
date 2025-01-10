#include<iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;
    // if (c >= 'a' && c <= 'z') {
    //     cout << "Your character is lowercase.";
    // } else {
    //     cout << "Your character is UPPERCASE.";
    // }
    if (c >= 65 && c <= 90) { // Implicit type conversion by compiler...
        cout << "Your character is UPPERCASE.";
    } else {
        cout << "Your character is lowercase.";
    }
    cout << "\n";
}