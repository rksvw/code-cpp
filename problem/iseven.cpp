#include <iostream>
using namespace std;

bool iseven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int num = 5;

    cout << (iseven(num) ? to_string(num) + " is even number.\n" : to_string(num) + " is odd number.\n");
    return 0;
}
