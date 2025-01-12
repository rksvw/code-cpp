#include<iostream>
#include<vector>
using namespace std;

int painterPartition(vector<int>& A, int n, int men) {
    int ans = 0;
    int minValue = 0;
    int maxValue = 0;
    if (men > n) {
        return -1;
    }

    for (int i = 0; i < n - 1; i++) {
        int ans1 = 0;
        ans += A[i];
        for (int j = i + 1; j < n; j++) {
            ans1 += A[j];

            if (j == n - 1) {
                maxValue = max(ans, ans1);
            }
        }
        if (i != 0) {
            minValue = min(minValue, maxValue);
        } else {
            minValue = maxValue;
        }
    }
    return minValue;
}

int main() {
    vector<int> num = {40, 30, 10, 20};
    int n = 4;
    int m = 2;
    cout << painterPartition(num, n, m) << endl;
    return 0;
}