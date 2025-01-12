#include<iostream>
#include<vector>
#include <climits>
using namespace std;

bool isValid(vector<int>& A, int n, int m, int maxAllowedTime) {
    int men = 1;
    int minute = 0;

    for (int i = 0; i < n; i++) { // log(N)
        if (A[i] > maxAllowedTime) {
            return false;
        }

        if (minute + A[i] <= maxAllowedTime) {
            minute += A[i];
        } else {
            men = men + 1;
            minute = A[i];
        }
    }

    return men <= m;
}

int Painter(vector<int>& A, int n, int m) {
    int maxValue = INT_MIN;
    if (m > n) {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        maxValue = max(maxValue, A[i]);
    }

    int st = maxValue;
    int en = sum;
    int ans = -1;

    while(st <= en) { // log(sum) or log(range) * log(n) -> O(nlog(sum))
        int mid = st + (en - st) / 2;

        if (isValid(A, n, m, mid)) { // left
            ans = mid;
            en = mid - 1;
        } else { // right
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> minutes = {40, 30, 10, 20};
    int n = 4;
    int men = 2;
    cout << Painter(minutes, n, men) << endl;
    return 0;
}