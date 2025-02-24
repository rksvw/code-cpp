#include <iostream>
#include<unordered_map>
using namespace std;

class NodeR
{
public:
    int data;
    NodeR *next;
    NodeR *random;

    NodeR(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
    }
};

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
private:
    Node *head;
    Node *tail;
    NodeR *nHead;
    NodeR *nTail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }
    Node* tempHead() {
        Node* temp = head;
        return temp;
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

    bool detectCycle() {
        Node* fast = head;
        Node* slow = head;
        int count = 0;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    Node* listCycle() {
        Node* fast = head;
        Node* slow = head;
        bool isCycle = false;

        while(fast->next != NULL && fast != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            return NULL;
        }

        slow = head;

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    void makeCycle(int pos) {
        Node* addr;
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
            pos--;
            if (pos == 0) {
                addr = temp;
            }
        }
        temp->next = addr;
        return;
    }

    int middleList() {
        Node* fast = head;
        Node* slow = head;
        int count = 1;
        while(fast->next != NULL && fast != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            count++;
        }
        return count;
    }

    void removeCycle() {
        Node* fast = head;
        Node* slow = head;
        Node* prev = NULL;
        bool isCycle = false;

        while (fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            return ;
        }

        slow = head;

        while (fast != slow)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
        head = slow;
        return;
    }
};

Node* mergeTwoList(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }

    if (head1->data <= head2->data) {
        head1->next = mergeTwoList(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeTwoList(head1, head2->next);
        return head2;
    }
}

Node* copyRandomList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    unordered_map<Node*, Node*> m;

    Node* newHead = new Node(head->data);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;

    while(oldTemp != NULL) {
        Node* copyNode = new Node(oldTemp->data);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    oldTemp = head;
    newTemp = newHead;

    while(oldTemp != NULL) {
        newTemp->random = m[oldTemp->random];
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }
}

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
    cout << ll.middleList() << endl;

    LinkedList l2;
    l2.push_back(5);
    l2.push_front(2);
    l2.push_back(7);
    l2.push_front(1);
    l2.push_back(10);
    l2.printList();
    cout<<l2.middleList()<< endl;
    ll.makeCycle(3);
    ll.detectCycle();
    cout << ((ll.listCycle())->data) << endl;
    ll.removeCycle();
    ll.printList();
    Node* newNode = mergeTwoList(ll.tempHead(), l2.tempHead());

    if (newNode == NULL || !newNode) {
        cout << "NULL Node" << endl;
        return 0;
    }

    do {
        cout << newNode->data << "->";
        newNode = newNode->next;
    } while(newNode != NULL);

    cout << "NULL" << endl;

    return 0;
}