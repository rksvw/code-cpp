#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node *child;

    Node(int val)
    {
        next = prev = child = NULL;
        data = val;
    }
};

class DublyList
{
public:
    Node *head;

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
            head = temp;
        }
    }

    void insertAtChild(int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->child = newNode;
            head = temp;
        }
    }


    Node* flattenList(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;
        while(curr != NULL) {
            if (curr->child != NULL) {
                // flatten the child node
                Node* next = curr->next;
                curr->next = flattenList(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // find the tail
                while(curr->next != NULL) {
                    curr = curr->next;
                }

                // attach tail with next ptr
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
    DublyList db;
    db.insertAtHead(1);
    db.insertAtTail(2);
    db.insertAtTail(3);
    db.insertAtChild(6);
    db.insertAtTail(7);
    db.insertAtChild(9);
    db.insertAtTail(10);
    db.insertAtTail(2);

    return 0;
}