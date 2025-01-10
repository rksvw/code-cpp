#include<iostream>
using namespace std;

int main() {
    int a;
    int b;
    int result;
    int input;
    cout << "Enter the number: " ;
    cin >> a;
    cout << "Enter the number: " ;
    cin >> b;
    cout << "Choose the operator: \n[+] -> 1\n[-] -> 2\n[*] -> 3\n[/] -> 4\n[%] -> 5\n";
    cin >> input;
    if (input == 1) {
        result = a + b;
        cout << "Result: " << result << "\n";
    }
    if (input == 2) {
        result = a - b;
        cout << "Result: " << result << "\n";
    }
    if (input == 3) {
        result = a * b;
        cout << "Result: " << result << "\n";
    }
    if (input == 4) {
        if (b == 0) {
            cout << "Error: Division by zero!\n";
            return 0;
        }
        float newResult = ((float)a / (float)b);
        cout << "Result: " << newResult << "\n";
    }
    if (input == 5) {
        if (b == 0) {
            cout << "Error: Division by zero!\n";
            return 0;
        }
        result = a % b;
        cout << "Result: " << result << "\n";
    }
}