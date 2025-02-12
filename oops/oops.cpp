#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void getInfo()
    {
        cout << "Person name : " << name << endl;
        cout << "Person age : " << age << endl;
    }
};

class Student : public Person
{
private:
    string studentId;
    string studentPassword;
    string randomId()
    {
        srand48(time(0));
        return to_string(rand());
    }

public:
    string course;
    string batch;
    int rollno;

    Student(string name, int age, string course, string batch, int rollno, string studentPass) : Person(name, age)
    {
        this->name = name;
        this->age = age;
        this->course = course;
        this->batch = batch;
        this->rollno = rollno;
        this->studentId = randomId();
        this->studentPassword = studentPass;
    }

    void getInfo()
    {
        cout << "Student Details in order:\n";
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Course : " << course << endl;
        cout << "Batch : " << batch << endl;
        cout << "RollNo. : " << rollno << endl;
        cout << "Id : " << studentId << endl;
        cout << "Password : " << studentPassword << endl;
    }
};

int main()
{
    Person p1("Ritik Sharma", 19);
    Person p2("Ankit Sharma", 20);

    Student s1(p1.name, p1.age, "Computer Science", "20250106A", 12345, "1256956ritik09p");
    s1.getInfo();
    cout << "\n";
    Student s2(p2.name, p2.age, "Texttile management", "20250105T", 12321, "1212120909ankit009p");
    s2.getInfo();
    return 0;
}