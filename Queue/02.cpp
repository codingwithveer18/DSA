#include <bits/stdc++.h>
using namespace std;

int main()
{
  deque<int> d;
  d.push_front(12);
  d.push_back(14);

  cout << d.front() << endl
       << d.back() << endl;

  d.pop_front();

  cout << d.front() << endl
       << d.back() << endl;
  d.pop_back();

  if (d.empty())
  {
    cout<<"QUEUE IS EMPTY"<<endl;
  }
  else
  {
        cout<<"QUEUE IS NOT EMPTY"<<endl;

  }
  return 0;
}