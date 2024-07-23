#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

  // Constructor
  Node(int dt)
  {
    this->data = dt;
    this->prev = NULL;
    this->next = NULL;
  }
  // Destructor
  ~Node()
  {
    int val = this->data;
    if (next != NULL)
    {
      delete next;
      next = NULL;
    }
    cout << "Deleting Node " << val << endl;
  }
};

void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    // cout << temp->data << " " ;
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int getLength(Node *head)
{
  int length = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    // cout << temp->data << " " ;
    length++;
    temp = temp->next;
  }
  return length;
}

void InsertAtHead(Node *&head, Node *&tail, int data) // taking reference of head to avoid making a copy of it
{

  if (head == NULL)
  {
    Node *temp = new Node(data);
    head = temp;
    tail = temp;
  }
  else
  {
    // Step-1 : Create new node first
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}
void InsertAtTail(Node *&tail, Node *&head, int data) // taking reference of head to avoid making a copy of it
{
  // Step-1 : Create new node first
  if (tail == NULL)
  {
    Node *temp = new Node(data);
    tail = temp;
    head = temp;
  }
  else
  {

    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void InsertAtMiddle(Node *&head, Node *&tail, int pos, int data)
{
  // Insert at starting node
  if (pos == 1)
  {
    InsertAtHead(head, tail, data);
    return;
  }
  Node *temp = head;
  int cnt = 1;
  while (cnt < (pos - 1))
  {
    temp = temp->next;
    cnt++;
  }
  // Insert at last node
  if (temp->next == NULL)
  {
    InsertAtTail(tail, head, data);
    return;
  }

  Node *nodetoinsert = new Node(data);
  nodetoinsert->next = temp->next;
  temp->next->prev = nodetoinsert;
  temp->next = nodetoinsert;
  nodetoinsert->prev = temp;
}

// Deleting a node
void Delete(int pos, Node *&head)
{
  if (pos == 1)
  {
    Node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while (cnt < pos)
    {
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    // if (curr->next != NULL)
    // {
    //   curr->next->prev = prev;
    // }
    curr->next = NULL;
    delete curr;
  }
}
int main()
{

  // Node *n1 = new Node(10);
  //  Node *head = n1;
  //  Node *tail = n1;
  Node *head = NULL;
  Node *tail = NULL;

  print(head);
  cout << getLength(head) << endl;

  InsertAtHead(head, tail, 11);
  print(head);
  InsertAtHead(head, tail, 12);
  print(head);

  cout << "Length of Current List is  : " << getLength(head) << endl;

  cout << "Inserting at tail" << endl;
  InsertAtTail(tail, head, 11);
  print(head);
  InsertAtTail(tail, head, 12);
  print(head);

  cout << "Length of Current List is  : " << getLength(head) << endl;

  cout << "Inserting in Middle" << endl;
  InsertAtMiddle(head, tail, 2, 20);
  print(head);
  InsertAtMiddle(head, tail, 1, 9);
  print(head);
  InsertAtMiddle(head, tail, 4, 50);
  print(head);

  cout << "Length of Current List is  : " << getLength(head) << endl;

  cout << "Deleting Node" << endl;
  Delete(7, head);
  print(head);

  cout << "Length of Current List is  : " << getLength(head) << endl;
  return 0;
}