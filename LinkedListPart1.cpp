// Q.1 In a singly linked list, deletion of data requires modification of how many pointers?
// 1
// 2
// 3
// Depends upon the node being deleted.
// Solution:2

// Q.2 Predict the output for linked list = 1->2->3->4->5:
// void traverse(Node* head) {
// while(head and head->next) {
// cout << head->data << ‘ ‘;
// head = head->next->next;
// }
// }
// 1.1 2 3 4 5
// 2.1 3 5
// 3.2 4
// 4.1 3

// Solution:4

// Q.3 Q3. Implement a Linked List class.
// The user defined LL should have insert (head,tail,idx) , delete(head,tail,idx) , get(idx) and display
// functions.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node*next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList()
    {
        head=tail=NULL;
        size=0;
    }

    void InsertAtBeginning(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void InsertAtEnd(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void InsertAtIndex(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid Index" << endl;
        } else if (idx == 0) {
            InsertAtBeginning(val);
        } else if (idx == size) {
            InsertAtEnd(val);
        } else {
            Node* t = new Node(val);
            Node* temp = head;
            for (int i = 1; i < idx; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    int getAtIndex(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid Index" << endl;
            return -1; // Return a default value or handle error case
        } else if (idx == 0) {
            return head->val;
        } else if (idx == size - 1) {
            return tail->val;
        } else {
            Node* temp = head;
            for (int i = 0; i < idx; i++) {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void DeleteAtHead() {
        if (size == 0) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (size == 0) {
            tail = nullptr;
        }
    }

    void DeleteAtTail() {
        if (size == 0) {
            cout << "List is Empty" << endl;
            return;
        }
        if (size == 1) {
            delete tail;
            head = tail = nullptr;
            size = 0;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }

    void deleteAtIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid Index" << endl;
            return;
        } else if (idx == 0) {
            DeleteAtHead();
        } else if (idx == size - 1) {
            DeleteAtTail();
        } else {
            Node* temp = head;
            for (int i = 1; i < idx; i++) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            size--;
        }
    }

    void Display() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;

    ll.InsertAtBeginning(1);
    ll.InsertAtBeginning(2);
    ll.InsertAtBeginning(3);
    ll.InsertAtBeginning(4);

    ll.InsertAtEnd(5);
    ll.InsertAtEnd(6);
    ll.InsertAtEnd(7);
    ll.InsertAtEnd(8);

    ll.InsertAtIndex(3, 9); // Corrected method name
    ll.InsertAtIndex(9, 10); // Corrected method name

    ll.Display();

    ll.DeleteAtHead();
    ll.DeleteAtTail();
    ll.deleteAtIdx(3); // Corrected method name

    ll.Display();

    cout << "Element at index 2: " << ll.getAtIndex(2) << endl;

    return 0;
}
