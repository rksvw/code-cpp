#include <iostream>
#include <vector>
using namespace std;

int lareEle(vector<int> num)
{
    int large = num[0];

    for (int i = 1; i < num.size(); i++)
    {
        if (large < num[i])
        {
            int tem = num[i];
            num[i] = large;
            large = tem;
        }
    }
    return large;
}

int main()
{
    vector<int> num = {1, 4, 50, 2, 5, 19, 3};

    cout << "Large element is: " << lareEle(num) << ".\n";
    return 0;
}
