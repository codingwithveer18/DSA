#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
  stack<int> s;
  int mid = q.size() / 2;
  int i = 0;
  // ex:- q = [ 1,2,3,4] => [1,4,2,3]

  // Push first half of queue elements into the stack
    // ex:- s => [1,2] q =>[3,4]
  while (i < mid)
  {
    int x = q.front();
    q.pop();
    s.push(x);
    i++;
  }

  // popping stack elements back to the queue
   // ex:- s => [] q =>[3,4,2,1]
  while (!s.empty())
  {
    int x = s.top();
    s.pop();
    q.push(x);
  }

  // popping first half elements of the queue and puting them back into queue

   // ex:- s => [] q =>[2,1,3,4]

  i = 0;
  mid = q.size() / 2;
  while (i < mid)
  {
    int val = q.front();
    q.pop();
    q.push(val);
    i++;
  }

  // Again push the first half elements into the stack

    // ex:- s => [2,1] q =>[3,4]
  i = 0;
  mid = q.size() / 2;
  while (i < mid)
  {
    int x = q.front();
    q.pop();
    s.push(x);
    i++;
  }

  // now pushing 1 element from stack and then poping first element from queue and again pushing back into that q

  // ex:- 1) s => [2,1] q =>[3,4]
  // 2) s => [2] q =>[3,4,1]
  // 3) s => [2] q =>[4,1,3]
  // 4) s => [] q =>[4,1,3,2]

  // 5) s => [] q =>[1,3,2,4]

  while (!s.empty())
  {
    int val = s.top();
    s.pop();
    q.push(val);
    int y = q.front();
    q.pop();
    q.push(y);
  }
}

int main()
{
  queue<int> q;

  // Fill the queue with some test data
  for (int i = 1; i <= 4; i++)
  {
    q.push(i);
  }

  // Display the original queue
  cout << "Original queue: ";
  queue<int> q_copy = q;
  while (!q_copy.empty())
  {
    cout << q_copy.front() << " ";
    q_copy.pop();
  }
  cout << endl;

  // Interleave the queue
  interLeaveQueue(q);

  // Display the interleaved queue
  cout << "Interleaved queue: ";
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  return 0;
}
