// FACTOR OF NTH SERIES
#include<iostream>
using namespace std;

int main() {
    int nSeries;
    int factorial = 1;

    cout << "Enter the Nth Series: ";
    cin >> nSeries;

    if (nSeries == 0) {
        cout << "Factorial of 0: 1";
        cout << "\n";
        return 0;
    }

    if (nSeries == 1) {
        cout << "Factorial of 1: 1";
        cout << "\n";
        return 0;
    }

    for (int i = 2; i <= nSeries; i++) {
        factorial = factorial * i;
    }

    cout << "Factorial of " << nSeries << ": " << factorial;
    cout << "\n";

    return 0;
}