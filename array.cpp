#include<iostream>
#include<climits>
using namespace std;

int main() {
    int marks[5];
    char name[20];

    int size = sizeof(marks) / sizeof(marks[0]);
    cout << "Size of array is : " << size << endl;

    for (int i = 0; i < size; i++) {
        cout << "Enter the element at index: " << i << ": ";
        cin >> marks[i];
    }

    int small = INT_MAX; // + infinity integer
    int large = INT_MIN; // - infinity integer
    int sIndex = 0;
    int lIndex = 0;
    for (int i = 0; i < size; i++) {
        if (marks[i] > large) {
            large = marks[i];
            lIndex = i; // Finding Index
        }
        // small = min(marks[i], small);
    }

    for (int i = 0; i < size; i++) {
        if (marks[i] < small) {
            small = marks[i];
            sIndex = i; // Finding Index
        }
        // large = max(marks[i], large);
    }
        cout << large << " is the largest integer in array, at Index: " << lIndex << endl;
        cout << small << " is the smallest integer in array, at Index: " << sIndex << endl;
    return 0;
}