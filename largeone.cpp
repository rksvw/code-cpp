#include <iostream>
using namespace std;

int largeOne(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b > c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

int main()
{
    int a, b, c;
    cout << "Enter three positive number: ";
    cin >> a >> b >> c;
    cout << "Largest one: " << largeOne(a, b, c) << endl;
    return 0;
}
