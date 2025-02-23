#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
private:
    string username, password;

public:
    User(string name, string pass)
    {
        username = name;
        password = pass;
    }
};

class UserManager
{
private:
    vector<User> users; // create object of vector

public:
    void RegisterUser()
    {
        string username, password;
        cout << "\t\tEnter your name: ";
        cin >> username;
        cout << "\t\tEnter password: ";
        cin >> password;

        User newUser(username, password);
        users.push_back(newUser);

        cout << "\t\t User Register Successfully ......" << endl;
    }
};

int main () {
    UserManager userManagers;

    int opt;
    cout << "\n\n\t\t1. Register User " << endl;
    cout << "\t\t2. Login " << endl;
    cout << "\t\t3. Show User List " << endl;
    cout << "\t\t4. Search User " << endl;
    cout << "\t\t5. Delete User " << endl;
    cout << "\t\t6. Exit " << endl;
    cout << "\t\tEnter your Choice : ";
    cin >> opt;
    switch (opt)
    {
    case 1:
        /* code */
        userManagers.RegisterUser();
        break;

    default:
        break;
    }
}