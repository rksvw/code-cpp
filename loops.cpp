#include<iostream>
using namespace std;

int main() {
    int i = 1;
    int n;
    cout << "Enter the nth series: ";
    cin >> n;
    // while (i <= n) {
    //     cout << i++ << "\n";
    //     // i++; // Post Increment
    // }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << "\n";
    // }

    do {
        cout << i << "\n";
        i++;
    } while (i <= n);
    return 0;
}