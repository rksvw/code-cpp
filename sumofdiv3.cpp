// SUM OF ALL NTH NUMBERS DIVISIBLE BY 3
#include<iostream>
using namespace std;

int main() {
    int nSeries;
    int sum = 0;

    cout << "Enter the nth series: ";
    cin >> nSeries;

    for (int i = 1; i <= nSeries; i++) {
        if (i % 3 == 0) {
            sum = sum + i;
        }
    }

    cout << "SUM OF " << nSeries << " (Divisible by 3): " << sum;
    cout << "\n";

    return 0;
}