#include<iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    int num, choose;

    cout << "choose want to print all the prime numbers: (1) for yes, (0) for no... ";
    cin >> choose;

    if (choose == 1) {
        cout << "Enter the Nth Series: ";
        cin >> num;
        for (int i = 0; i <= num; i++) {
            if (isPrime(i)) {
                cout << i << " is a prime number.\n";
            }
            else {
                cout << i << " is not a prime number.\n";
            }
        }
    }
    else if (choose == 0) {
        cout << "Enter a number: ";
        cin ;
        cin >> num;
        if (isPrime(num)) {
            cout << num << " is a prime number.";
            cout << "\n";
        } else {
            cout << num << " is not a prime number.";
            cout << "\n";
        }

    }else {
        cout << "Error: Invalid Input!\n";
    }
    return 0;
}