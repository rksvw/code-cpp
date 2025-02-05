#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> ps;
    int countS = 0;
    int countC = 0;
    int countCu = 0;

    if (s.length() <= 1)
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (ps.empty())
        {
            ps.push(s[i]);
        }
        else
        {
            if (s[i] == '}' && ps.top() == '{')
            {
                countCu--;
                ps.pop();
            }
            else if (s[i] == ')' && ps.top() == '(')
            {
                countC--;
                ps.pop();
            }
            else if (s[i] == ']' && ps.top() == '[')
            {
                ps.pop();
                countS--;
            }
            else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                if (s[i] == '(')
                {
                    countC++;
                }
                else if (s[i] == '{')
                {
                    countCu++;
                }
                else
                {
                    countS++;
                }
                ps.push(s[i]);
            }
            else
            {
                return false;
            }
        }
    }

    if (!ps.empty())
    {
        return false;
    }

    if (countC < s.length() && countC > 0)
    {
        return false;
    }
    else if (countCu < s.length() && countCu > 0)
    {
        return false;
    }
    else if (countS < s.length() && countS > 0)
    {
        return false;
    }
    return true;
}

int main()
{
    cout << isValid("{([") << endl;
    return 0;
}