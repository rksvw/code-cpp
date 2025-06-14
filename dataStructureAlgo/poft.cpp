#include <iostream>
using namespace std;

bool isPowerOfTwo(int);

int main()
{
    cout << isPowerOfTwo(34) << endl;
    return 0;
}

bool isPowerOfTwo(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return (n / 2);
    }
    else
    {
        return 0;
    }
}
