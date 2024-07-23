#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next; // Representing next node's memory address

  // constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  // Destructor
  ~Node()
  {
    int val = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
  }
};

// Traversing a linked list
void print(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {

    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void InsertatTail(Node *&tail, Node *curr)
{
  tail->next = curr;
  tail = curr;
}
void sortList(Node *&head)
{
  Node *zeroHead = new Node(-1);
  Node *zeroTail = zeroHead;
  Node *oneHead = new Node(-1);
  Node *oneTail = oneHead;
  Node *twoHead = new Node(-1);
  Node *TwoTail = twoHead;

  Node *curr = head;
  while (curr != NULL)
  {
    int val = curr->data;
    if (val == 0)
    {
      InsertatTail(zeroTail, curr);
    }
    else if (val == 1)
    {
      InsertatTail(oneTail, curr);
    }
    else
    {
      InsertatTail(TwoTail, curr);
    }
    curr = curr->next;
  }
  if (oneHead->next != NULL)
  {
    zeroTail->next = oneHead->next;
  }
  else
  {
    zeroTail->next = twoHead->next;
  }
  oneTail->next = twoHead->next;
  TwoTail->next = NULL;
  head = zeroHead->next;
}

void InsertAtHead(Node *&head, int data) // taking reference of head to avoid making a copy of it
{
  // Step-1 : Create new node first
  Node *temp = new Node(data);

  // changing temp-> next to head

  temp->next = head;
  head = temp;
}
int main()
{
  Node *head = NULL;
  InsertAtHead(head, 1);
  InsertAtHead(head, 0);
  InsertAtHead(head, 1);
  InsertAtHead(head, 0);
  InsertAtHead(head, 2);
  InsertAtHead(head, 1);

  sortList(head);
  print(head);

  return 0;
}