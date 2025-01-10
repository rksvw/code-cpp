#include<iostream>
using namespace std;

int sumOfDigit(int num) {
    int sum = 0;
    int rem;
    int tem = num;

    while (num != 0) {
        rem = num % 10;
        sum = sum + rem;
        num = num / 10;
    }

    return sum;
}

int main() {
    int num;
    cout << "Enter any number or digit: ";
    cin >> num;

    int sum = sumOfDigit(num);
    cout << sum;
    cout << "\n";
}