#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 4, 5, 8, 12};
    int i, n = 5, item = 3;

    cout << "The original array elements are: \n";
    for (i = 0; i < n; i++)
    {
        cout << "Array arr[" << i << "] = " << arr[i] << endl;
    }

    arr[n - 3] = item;
    cout << "The updated array elements are: \n";
    for (i = 0; i < n; i++)
    {
        cout << "Update arr[" << i << "] = " << arr[i] << endl;
    }
    return 0;
}
