#include<iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;

    // Using 2 cout
    ((c >= 65) && (c <= 90)) ? cout << "UPPERCASE" : cout << "lowercase" ;
    cout << "\n";

    // Using 1 cout
    // cout << (((c >= 65) && (c <= 90)) ? "UPPERCASE" : "lowercase" );
    return 0;
}