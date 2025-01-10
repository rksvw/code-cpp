#include<iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int nCrResult(int nFact, int rFact, int nRFact) {
    return nFact / ((rFact)*(nRFact));
}

int main() {
    int n;
    int r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    int factN = factorial(n);
    int factR = factorial(r);
    int factNR = factorial(n - r);

    int nCr = nCrResult(factN, factR, factNR);
    cout << nCr;
    cout << "\n";
}