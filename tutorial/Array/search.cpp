#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 5, 2, 6, 9, 8};
    int n = 6, i, tar = 6, flag = 0;

    cout << "The original array elements are : \n";
    for (i = 0; i < n; i++)
    {
        cout << "Array[" << i << "] = " << arr[i] << endl;
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] == tar)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << "Found element " << tar << " at position " << i + 1 << endl;
    }
    else
    {
        cout << "Element " << tar << " is not exists\n";
    }
    return 0;
}
