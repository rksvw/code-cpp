#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
           tail->next = newNode;
           tail = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void pop_back() {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->next->next == NULL) {
                cout << temp->next->data << endl;
                // deleting the last node of node from the Heap memory
                delete temp->next;
                temp->next = NULL;
                tail = temp;
            }
            temp = temp->next;
        }
    }

    void new_pop_back() {
        if (head == NULL) {
            cout << "Empty List" << endl;
        }
        Node* temp = head;

        while(temp->next != tail) {
            temp = temp->next;
        }
        cout << tail->data << endl;
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) {
        Node* temp = head;
        int flag = 0;
        int count = 0;
        if (temp == NULL) {
            cout << "Empty List" << endl;
        }
        if (pos < 0) {
            cout << "Out off Stack" << endl;
            return;
        }
        // for 0th index
        if (pos == 0) {
            Node* newNode = new Node(val);
            newNode->next = temp;
            head = newNode;
            flag = 1;
        }
        // for nth index
        while(temp != tail) {
            if (count == (pos - 1)) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                flag = 1;
                break;
            }
            temp = temp->next;
            count += 1;
        }

        if (!flag) {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop_front() {
        Node *temp = head;
        if (temp != NULL) {
            cout << temp->data << endl;
            head = head->next;
            delete temp;
        } else {
            cout << "Empty LinkedList" << endl;
            return;
        }
    }

    int searchList(int srch) {
        Node* temp = head;

        if (temp == NULL) {
            cout << "Empty List" << endl;
            return -1;
        }

        for (int i = 0; temp != NULL; i++) {
            if (temp->data == srch) {
                return i;
            }
            temp = temp->next;
        }

        if (true) {
            cout << srch << " is not in the List";
            return -1;
        }
    }

    void reverseList() {
        Node* next = NULL;
        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
       head = prev;
    }
};

int main()
{
    LinkedList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.printList();
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.printList();
    ll.pop_front();
    ll.pop_front();
    ll.printList();
    ll.new_pop_back();
    ll.new_pop_back();
    ll.pop_back();
    ll.printList();
    ll.push_front(90);
    ll.push_back(89);
    ll.printList();
    ll.insert(100, 0);
    ll.printList();
    ll.insert(500, 2);
    ll.printList();
    ll.insert(900, 0);
    ll.printList();
    ll.insert(1000, 6);
    ll.printList();
    ll.insert(1100, 15);
    ll.printList();
    ll.insert(1100, 5);
    ll.printList();
    ll.insert(1900, -8);
    ll.printList();
    cout <<ll.searchList(80) << endl;
    cout <<ll.searchList(1) << endl;
    ll.printList();
    ll.reverseList();
    ll.printList();
    return 0;
}