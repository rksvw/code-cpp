#include <iostream>
#include <math.h>
using namespace std;

int power(int);

int main()
{
    int num = 26;

    cout << ((num & (num - 1)) == 0) << endl;

    if (pow(2, 30) % num == 0)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}

int power(int num)
{
    if (num == 0)
    {
        return false;
    }

    if (num == 1)
    {
        return true;
    }

    if (num % 2 != 0)
    {
        return false;
    }
    else
    {
        return power(num / 2);
    }
}
