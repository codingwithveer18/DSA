#include <bits/stdc++.h>
using namespace std;

class MyStack
{
  queue<int> q1;
  queue<int> q2;

public:
  MyStack() {}

  void push(int x)
  {
    q2.push(x);
    while (!q1.empty())
    {
      int val = q1.front();
      q2.push(val);
      q1.pop();
    }
    swap(q1, q2);
  }

  int pop()
  {
    int val = q1.front();
    q1.pop();
    return val;
  }

  int top() { return q1.front(); }

  bool empty()
  {
    return q1.empty();
  }
};
int main()
{
  MyStack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  cout << "Top element: " << stack.top() << endl;

  stack.pop();
  stack.pop();
  stack.pop();

  cout << "Top element after pop: " << stack.top() << endl;

  cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

  return 0;
}