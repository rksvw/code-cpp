#include <iostream>
#include<unistd.h>
#include<cstdlib>
#include<signal.h>
using namespace std;

void signal_callback_handler(int signum) {
    cout << "->NULL" << signum << endl;
    // Terminate program
    exit(signum);
}

class Node
{
public:
    /* data */
    Node *next;
    int data;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularList
{
private:
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            tail = head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        tail->next = head;
        return;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "->NULL";
        }

        signal(SIGINT, signal_callback_handler);
        while (tail != NULL)
        {
            cout << tail->data << "->";
            tail = tail->next;
            // sleep(1);
        }

        cout << "->NULL" << endl;
        return;
    }

    void print() {
        if (head == NULL) return;

        cout << head->data << "->";
        Node* temp = head->next;

        while(temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << temp->data << "->NULL" << endl;
    }
};

int main()
{
    CircularList cl;
    cl.insertAtHead(5);
    cl.insertAtHead(6);
    cl.insertAtHead(7);
    cl.print();
    return 0;
}