#include<iostream>
#include<string>
using namespace std;

int revNum(int num) {
    static int sum = 0; // Static function are used to increment the number in a return,
    if (num == 0) {     // function multiple times even if you assigned it 0 already at start of function.
        return sum;
    }
    int rem = num % 10;
    sum = sum * 10 + rem;
    return revNum(num / 10);
}

// Reverse the Number or isPalindrome
bool isPalindrome(int x) {
    string str = to_string(x);
    for(int i = 0, j = str.length() - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    cout << "Enter any number (3-DigitLong): ";
    cin >> number;

    if (number < 0) {
        cout << "Error: Positive Integer Only!\n";
        return 0;
    }

    int reverse = revNum(number);
    cout << "Reverse of " << number << " is " << reverse << ".\n";

    if (isPalindrome(reverse)) {
        cout << reverse << " is a Palindrome Number.\n";
    } else {
        cout << reverse << " is not a Palindrome Number.\n";
    }

    return 0;
}