#include <iostream>
using namespace std;

int func(int);

int main()
{
    int num = 5;
    int value = func(num);
    cout << value << endl;
    return 0;
}

int func(int value)
{
    static int x = 0;
    if (value > 0)
    {
        x++;
        return func(value - 1) + x;
    }
    return 0;
}
