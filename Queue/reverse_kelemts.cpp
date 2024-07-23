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
  Stack s(5);
  queue<int> q;
  vector<int> val = {1, 2, 3, 4, 5};

  // pushing vector's value to the queue
  for (int i = 0; i < val.size(); i++)
  {
    q.push(val[i]);
  }
  cout << "Before Reverse: " << endl;

  for (int i = 0; i < q.size(); i++)
  {
    cout << val[i] << " ";
  }

  cout << endl;
  int i = 0;
  int k;
  cout << "Enter a number for reversing values" << endl;
  cin >> k;
  cout << "Elements to be Reversed: " << endl;
  // pushing k elements to stack
  while (i < k)
  {
    int element = q.front();
    cout << element << " ";
    q.pop();
    s.push(element);
    i++;
  }
  cout << endl;

  // pushing elements from stack in reversed order from stack into queue
  while (!s.isEmpty())
  {
    int element = s.peek();
    s.pop();
    q.push(element);
  }

  // step 3 : fetch n-k elemets from queue and push back them
  int t = q.size() - k;
  while (t--)
  {
    int val = q.front();
    q.pop();
    q.push(val);
  }

  // Printing reversed k elements of queue
  cout << "Reversing k elements :" << endl;
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}