#include <iostream>
using namespace std;
int main()
{
    int LA[] = {1, 2, 3, 4, 5};
    int i, n = 5;
    cout << "The original array elements are :" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    for (i = 1; i < n; i++)
    {
        LA[i] = LA[i + 1];
        n = n - 1;
    }

    cout << "The array elements after deletion : " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    cout << "LA index 3 = " << LA[4] << endl;

    return 0;
}
