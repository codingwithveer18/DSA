#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
  int *arr;
  int top;
  int size;
  Stack(int size)
  {
    this->size = size;
    arr = new int[size];
    top = -1;
  }
  void push(int element)
  {
    if (size - top > 1)
    {
      top++;
      arr[top] = element;
    }
    else
    {
      cout << "Stack OverFlow" << endl;
    }
  }
  void pop()
  {
    if (top >= 0)
    {
      top--;
    }
    else
    {
      cout << "Stack UnderFlow" << endl;
    }
  }
  bool isEmpty()
  {
    if (top == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  int peek()
  {
    if (top >= 0)
    {
      return arr[top];
    }
    else
    {
      cout << "Stack is Empty" << endl;
      return -1;
    }
  }
};
int main()
{
  cout<<"Reversing  queue using stack"<<endl;
   Stack s(5);
  queue<int> q;
  vector<int> val = {1, 2, 3, 4, 5};
  cout<<"Before Reverse : " <<endl;
  for (int i = 0;i < val.size(); i++)
  {
    q.push(val[i]);
  }
  while (!q.empty())
  {
    int element = q.front();
    cout<<element<<" ";
    q.pop();
    s.push(element);
  }
  cout<<endl;
  while (!s.isEmpty())
  {
    int element = s.peek();
    s.pop();
    q.push(element);
  }
  cout << "After Reverse :" << endl;
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}