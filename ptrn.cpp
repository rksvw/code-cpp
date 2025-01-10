#include<iostream>
using namespace std;

int main() {
    int n ;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        for (int j = 0; j <= n - i - 1; j++) {
            if (j == (n - i - 1)) {
                cout << "*";
            }
        }

        for (int j = 0; j < (i*2)-1; j++) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            if (j == i)
                cout << "*";
        }
        cout << "\n";
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0 ; j < i+1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            if (j == i) {
                cout << "*";
            }
        }

        for (int j = 1; j <= ((n -2) * 2) - 1; j++) {
            cout << " ";
        }

        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                cout << "*";
            }
        }
        cout << "\n";
    }
}