#include <iostream>
#include <vector>
using namespace std;

int searchEle(vector<int> num, int tar)
{
    for (int i = 0; i < num.size(); i++)
    {
        if (tar == num[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> num = {1, 2, 4, 7, 3, 12, 9, 15};
    int tar = 7;

    int index = searchEle(num, tar);
    cout << "Target number " << tar << (index == -1 ? " is not in vector.\n" : " exists at index " << to_string(index) << ".\n");
    return 0;
}
