#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 5, 6, 8};
    int i, n = 6;

    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++)
    {
        cout << "Array arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}
