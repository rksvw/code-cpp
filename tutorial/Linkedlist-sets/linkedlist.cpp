#include <iostream>
#include <string>
using namespace std;

/**
 * Template in C++ allows us to create generic classes and functions
 * that can work with any data type. It enables type-independent code
 * while maintaining type safety. The compiler generates specific code
 * for each type used with the template at compile time.
 *
 * For example, this Node template class can store integers, strings,
 * or any other data type without having to rewrite the class for each type.
 */
template <typename T>
class Node
{
public:
    Node *next;
    T data;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void push_back(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node<T> *x = head;

            while (x->next != NULL)
            {

                x = x->next;
            }
            x->next = newNode;
        }
    }

    void print()
    {
        Node<T> *x = head;
        while (x != NULL)
        {
            cout << x->data << "->";
            x = x->next;
        }
        cout << "NULL\n";
    }

    void push_front(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node<T> *x = head;
            newNode->next = x;
            head = newNode;
        }
    }

    void insert(T data, int index)
    {
        Node<T> *newNode = new Node<T>(data);
        Node<T> *x = head;

        while (index != 1)
        {

            x = x->next;
            index--;
        }
        newNode->next = x->next;
        x->next = newNode;
    }

    void deleteAtFirst()
    {
        Node<T> *x = head;
        Node<T> *temp;

        temp = x;
        head = x->next;
        delete temp;
    }

    void deleteAtEnd()
    {
        Node<T> *x = head;
        Node<T> *temp;

        while (x->next->next != NULL)
        {
            x = x->next;
        }

        temp = x->next;
        x->next = NULL;
        delete temp;
    }

    void deleteAt(T data)
    {
        Node<T> *x = head;
        Node<T> *temp;

        while (x->next->data != data)
        {
            x = x->next;
        }

        temp = x->next;
        x->next = x->next->next;
        delete temp;
        return;
    }

    int search(T data)
    {
        Node<T> *x = head;
        int count = 1;
        while (x->data != data)
        {
            if (x->next == NULL)
            {
                return -1;
            }
            x = x->next;
            count = count + 1;
        }
        return count;
    }
};

int main()
{
    LinkedList<string> l1; // Fixed: Added <int> to specify the template type
    l1.push_back("Ritik");
    l1.push_back("Raghav");
    l1.push_back("Rohan");
    l1.push_back("Ritvik");
    l1.push_back("Arman");
    l1.push_front("Mohan");
    l1.push_front("Arval");
    l1.push_front("katsEye");
    l1.insert("RRR", 3);
    l1.deleteAt("Mohan");
    l1.print();
    l1.deleteAtFirst();
    l1.print();
    l1.deleteAtEnd();
    l1.print();

    cout
        << l1.search("Arman") << endl;
    return 0;
}
