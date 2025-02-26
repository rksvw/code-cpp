#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
private:
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void printNode() {
        Node* temp = head;

        while( temp != NULL) {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop_front() {
        Node* temp = head;
        if (head == NULL) {
            cout << "Empty List!\n" << endl;
            return;
        }
        cout << temp->data << endl;
        head = temp->next;
        temp->prev = NULL;
        delete temp;
    }

    void pop_back() {
        Node* temp = tail;
        if (tail == NULL) {
            cout << "Empty List!" << endl;
            return;
        }
        cout << temp->data << endl;
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }


};

int main() {

    DoublyList dll;
    dll.push_front(5);
    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.printNode();
    dll.push_back(6);
    dll.push_back(7);
    dll.printNode();
    dll.pop_front();
    dll.pop_front();
    dll.printNode();
    dll.pop_back();
    dll.printNode();
    dll.pop_back();
    dll.printNode();
    dll.pop_back();
    dll.printNode();
    return 0;
}