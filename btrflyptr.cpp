#include<iostream>
using namespace std;

int main() {
    int nTerm;
    cout << "Enter the Nth Pattern: ";
    cin >> nTerm;

    for (int i = 0; i < nTerm; i++) {
        for (int j = 0; j < i+1; j++) {
            cout << "*";
        }
        if (i != (nTerm -1)) {
            for (int j = 0; j < (nTerm - i - 1)*2; j++) {
                cout << " ";
            }
        }

        for (int j = 0; j < i+1; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 0; i < nTerm; i++) {
        for (int j = (nTerm - i); j > 0; j--) {
            cout << "*";
        }

        if (i != 0) {
            for (int j = 0; j < (i * 2); j++) {
                cout << " ";
            }
        }
        for (int j = nTerm - i; j > 0; j--) {
            cout << "*";
        }
        cout << "\n";
    }

}