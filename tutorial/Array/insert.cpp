#include <iostream>
using namespace std;

int main()
{
    int LA[3] = {}, i;
    cout << "Array Before Intertion: \n";
    for (i = 0; i < 3; i++)
    {
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    // ! prints garbase values
    cout << "Inserting elements..." << endl;
    cout << "Array After Insertion:" << endl;
    for (i = 0; i < 10; i++)
    {
        LA[i] = i + 2;
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    cout << "Array index 8 " << LA[8] << endl;

    return 0;
}
