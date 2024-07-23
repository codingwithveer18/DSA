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
void Insertnode(Node *&tail, int ele, int data)
{
  // empty list
  if (tail == NULL)
  {
    Node *newNode = new Node(data);
    tail = newNode;
    newNode->next = newNode;
  }
  else
  {
    // non empty list
    Node *curr = tail;
    while (curr->data != ele)
    {
      curr = curr->next;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
  }
}

// Traversing a linked list
void print(Node *&tail)
{
  Node *temp = tail;
  if (tail == NULL)
  {
    cout << "List is Empty" << endl;
    return;
  }
  do
  {
    cout << tail->data << " ";
    tail = tail->next;
  } while (tail != temp);
  cout << endl;
}

void Delete(Node *&tail, int ele)
{

  // empty list
  if (tail == NULL)
  {
    cout << "list is empty" << endl;
    return;
  }
  else
  {
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != ele)
    {
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    // 1 node LL
    if (curr == prev)
    {
      tail = NULL;
    }
    if (tail == curr)
    {
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}


int main()
{
  Node *tail = NULL;
  Insertnode(tail, 1, 5);
  Insertnode(tail, 5, 6);
  Insertnode(tail, 6, 7);
  print(tail);
  cout << "Inserting in middle" << endl;
  Insertnode(tail, 5, 8);
  print(tail);

  Delete(tail, 5);
  print(tail);
  Delete(tail, 8);
  print(tail);
  Delete(tail, 6);
  print(tail);
  Delete(tail, 7);
  print(tail);
  
  return 0;
}