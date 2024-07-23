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
    cout << "Deleting Node " << val << endl;
  }
};
void InsertAtHead(Node *&head, int data) // taking reference of head to avoid making a copy of it
{
  // Step-1 : Create new node first
  Node *temp = new Node(data);

  // changing temp-> next to head

  temp->next = head;
  head = temp;
}
void InsertAtTail(Node *&tail, int data) // taking reference of tail to avoid making a copy of it
{
  // Step-1 : Create new node first
  Node *temp = new Node(data);

  // changing temp-> next to tail

  tail->next = temp;
  tail = temp;
  // or tail= tail->next ;
}

void InsertAtMiddle(Node *&head, Node *&tail, int pos, int data)
{
  // Insert at starting node
  if (pos == 1)
  {
    InsertAtHead(head, data);
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
    InsertAtTail(tail, data);
    return;
  }

  Node *nodetoinsert = new Node(data);
  nodetoinsert->next = temp->next;
  temp->next = nodetoinsert;
}

// Deleting a node
void Delete(int pos, Node *&head)
{
  if (pos == 1)
  {
    Node *temp = head;
    head = head->next;
    // Freeing the memory
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
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

// Traversing a linked list
void print(Node *&head)
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

bool DetechLoop(Node *&head)
{
  if (head == NULL)
  {
    return false;
  }
  map<Node *, bool> visited;

  Node *temp = head;
  while (temp != NULL)
  {
    if (visited[temp] == true)
    {
      cout << "At Element : " << temp->data << " ";
      return true;
    }
    visited[temp] = true;
    temp = temp->next;
  }
  return false;
}

Node *StartNode(Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }
  Node *intersection = FloydCycle(head);
  Node *slow = head;
  while (slow != intersection)
  {
    slow = slow->next;
    intersection = intersection->next;
  }
  return slow;
}
void Removeloop(Node *head)
{
  if (head == NULL)
  {
    return;
  }
  Node *startingloop = StartNode(head);
  Node *temp = startingloop;
  while (temp->next != startingloop)
  {
    temp = temp->next;
  }
  temp->next = NULL;
}
int main()
{
  Node *n1 = new Node(10); // Created object in heap
  cout << n1->data << endl;
  cout << n1->next << endl;

  // head pointed to n1
  Node *head = NULL;
  // tail pointed to n1
  Node *tail = n1;
  cout << "Before insertion " << endl;
  print(head);
  InsertAtHead(head, 12);
  cout << "After insertion 12" << endl;
  print(head);
  cout << "After insertion 15" << endl;
  InsertAtHead(head, 15);
  print(head);

  InsertAtTail(tail, 12);
  cout << "Inserting 12 at tail" << endl;
  print(head);
  cout << "Inserting 18 at tail" << endl;
  InsertAtTail(tail, 18);
  print(head);

  InsertAtMiddle(head, tail, 5, 20);
  cout << "Inserting 20 at Middle" << endl;
  print(head);

  // verifying position of head and tail
  cout << "head " << head->data << endl;
  cout << "tail " << tail->data << endl;

  // Deleting
  // Delete(3, head);
  // print(head);
  // Delete(1, head);
  // print(head);

  tail->next = head->next;
  if (DetechLoop(head))
  {
    cout << " | CYCLE PRESENT" << endl;
  }
  else
  {
    cout << "NO CYCLE PRESENT" << endl;
  }
  if (FloydCycle(head) != NULL)
  {
    cout << "CYCLE PRESENT AT (from tail): " << FloydCycle(head)->data << endl;
  }
  else
  {
    cout << "NO CYCLE PRESENT" << endl;
  }
  Node *loop = StartNode(head);
  cout << "Starting Node of Loop is " << loop->data << endl;
  Removeloop(head);
  print(head);

  return 0;
}