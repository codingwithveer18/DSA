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
  bool isEmpty()
  {
    if (top == -1)
    {
      cout << "Stack is Empty" << endl;
      return true;
    }
    else
    {
      cout << "Stack is Not Empty" << endl;
      return false;
    }
  }
};

int main()
{
  Stack st(5);

  st.push(20);
  st.push(15);
  st.push(10);
  st.push(8);
  st.push(4);

  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  st.pop();
  cout << st.peek() << endl;
  // cout << st.isEmpty() << endl;

  return 0;
}