#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &A, int n, int men, int mid) {
    int student = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > mid) {
            return false;
        }

        if (pages + A[i] <= mid) {
            pages = pages + A[i];
        } else {
            student = student + 1;
            pages = A[i];
        }
    }

    return student > men ? false : true;
}

int bookAllocate(vector<int> &A, int n, int men) {
    if (men > n) {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + A[i];
    }

    int start = 0;
    int end = sum;
    int ans = -1;

    while (start <= end)
    {
        /* code */
        int mid = start + (end - start) / 2;
        if (isValid(A, n, men, mid))
        {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {2, 1, 3, 4};
    int n = 4;
    int m = 2;

    cout << bookAllocate(A, n, m) << endl;
    return 0;
}