#include <bits/stdc++.h>
using namespace std;

class kqueue
{

public:
  int n, k, *front, *rear, *arr, freespot, *next;

public:
  kqueue(int n, int k)
  {
    this->n = n;
    this->k = k;
    front = new int[k];
    rear = new int[k];

    for (int i = 0; i < k; i++)
    {
      front[i] = -1;
      rear[i] = -1;
    }

    next = new int[n];
    for (int i = 0; i < n; i++)
    {
      next[i] = i + 1;
    }
    next[n - 1] = -1;
    arr = new int[n];
    freespot = 0;
  }

  void enque(int data, int qn)
  {
    // overflow
    if (freespot == -1)
    {
      cout << "No empty space available" << endl;
      return;
    }
    // find first free index
    int index = freespot;
    freespot = next[index];
    // check whether it is first element
    if (front[qn - 1] == -1)
    {
      front[qn - 1] = index;
    }
    else
    {
      // linking new element to previous element
      next[rear[qn - 1]] = index;
    }
    next[index] = -1;
    rear[qn - 1] = index;
    arr[index] = data;
  }

  int deque(int qn)
  {
    // underflow
    if (front[qn - 1] == -1)
    {
      cout << "underfllow" << endl;
      return -1;
    }
    // find index
    int index = front[qn - 1];
    // update front position of queue's to its next element
    front[qn - 1] = next[index];
    // updating next and freespot
    next[index] = freespot;
    freespot = index;
    return arr[index];
  }
};

int main()
{
  kqueue q(10, 3);
  q.enque(10, 1);
  q.enque(15, 1);
  q.enque(20, 2);
  q.enque(25, 1);
  cout<<q.deque(1)<<endl;
  cout<<q.deque(2)<<endl;
  cout<<q.deque(1)<<endl;
  cout<<q.deque(1)<<endl;
  cout<<q.deque(1)<<endl;

      return 0;
}