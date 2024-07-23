#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
  stack<int> s1;
  stack<int> s2;

public:
  MyQueue() {}

  void push(int x)
  {
    while (!s1.empty())
    {
      int val = s1.top();
      s2.push(val);
      s1.pop();
    }
    s2.push(x);
    while (!s2.empty())
    {
      int val = s2.top();
      s1.push(val);
      s2.pop();
    }
  }

  int pop()
  {
    int val = s1.top();
    s1.pop();
    return val;
  }

  int peek() { return s1.top(); }

  bool empty()
  {
    if (s1.empty())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};
int main()
{
  MyQueue q;

  q.push(1);
  q.push(2);
  q.push(3);

  cout << "Top element: " << q.peek() << endl;

  q.pop();

  cout << "Top element after pop: " << q.peek() << endl;

  cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

  return 0;
}