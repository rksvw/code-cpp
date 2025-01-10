#include<iostream>
using namespace std;

void changeArr(int arr[], int size) {
    cout << "in function\n";
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    int size = sizeof(arr) / sizeof(arr[0]);
    changeArr(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}