#include <iostream>
using namespace std;

float fact(float);
float expo(int, float);
float taylor(int, float);
float taylorSum(int, float);
double e(int, int);
double e1(int, int);

int main()
{
    int x = 2;
    float n = 10;
    cout << taylorSum(x, n) << endl;
    cout << e(x, n) << endl;
    cout << e1(x, n) << endl;
    return 0;
}

// taylor bruteforce approach
float taylorSum(int x, float n)
{
    if (n == 0)
    {
        return 1;
    }
    return taylor(x, n) + taylorSum(x, n - 1);
}

float taylor(int x, float n)
{
    if (n == 0)
    {
        return 1;
    }
    return expo(x, n) / fact(n);
}

float expo(int m, float n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return m;
    }

    if (int(n) % 2 == 0.0)
    {
        return expo((m * m), (n / 2));
    }
    else
    {
        return m * expo((m * m), ((n - 1) / 2));
    }
}

float fact(float num)
{
    if (num == 1)
    {
        return 1;
    }
    return fact(num - 1) * num;
}

// Taylor using recursive approach
double e(int x, int n)
{
    static double s;
    if (n == 0)
    {
        return s;
    }
    s = 1 + x * s / n;
    return e(x, n - 1);
}

// Taylor using loop approach
double e1(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for (i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += (num / den);
    }
    return s;
}
