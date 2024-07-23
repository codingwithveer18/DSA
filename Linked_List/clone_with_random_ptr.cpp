#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next; 
    Node *random; // Representing random node's memory address

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    // Destructor
    ~Node() {
        int val = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        // cout << "Deleting Node " << val << endl;
    }
};

void InsertAtTail(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* copy(Node *head) {
    if (!head) return NULL;

    // Step -1 : create a clone list
    Node *temp = head;
    while (temp != NULL) {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    // Step -2 : Copy Random pointers
    temp = head;
    while (temp != NULL) {
        if (temp->next != NULL) {
            temp->next->random = temp->random ? temp->random->next : NULL;
        }
        temp = temp->next ? temp->next->next : NULL;
    }

    // Step -3 : Separate the cloned list from the original list
    Node *originalNode = head;
    Node *cloneHead = head->next;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL) {
        originalNode->next = originalNode->next ? originalNode->next->next : NULL;
        cloneNode->next = cloneNode->next ? cloneNode->next->next : NULL;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << "[" << temp->data << " | Next: " << (temp->next ? to_string(temp->next->data) : "NULL") 
             << " | Random: " << (temp->random ? to_string(temp->random->data) : "NULL") << "] ";
        temp = temp->next;
        if (temp != NULL) {
            cout << " -> ";
        }
    }
    cout << endl;
}


int main() {
    // Creating the original linked list
    Node *head = new Node(1);
    Node *tail = head;
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);

    // Setting up random pointers
    head->random = tail;         // 1's random points to 4
    head->next->random = head;   // 2's random points to 1
    tail->random = head->next;   // 4's random points to 2

    cout << "Original list:\n";
    printList(head);

    // Copy the list
    Node *clonedList = copy(head);

    cout << "Cloned list:\n";
    printList(clonedList);

    // Cleanup
    delete head;
    delete clonedList;

    return 0;
}
