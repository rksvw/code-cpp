#include<iostream>
using namespace std;

void fiboSeries(int n) {
    int prev = 0;
    int next = 1;
    int now = 0;

    for (int i = 2; i <= n-1; i++) {
        now = prev + next;
        cout << now << "\n";
        prev = next;
        next = now;
    }
}

int main() {
    int nSeries;
    cout << "Enter the Nth Series: ";
    cin >> nSeries;

    cout << "Fibonacci Series: \n0\n1\n";
    fiboSeries(nSeries);
    return 0;
}