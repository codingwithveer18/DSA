#include <bits/stdc++.h>
using namespace std;

int main()
{
  // create a queue
  queue<int> q;
  q.push(1);
  q.push(10);
  q.push(11);
cout<<q.front()<<endl;
  cout << q.size();

  q.pop();
  if(q.empty())
{
  cout<<"queue is empty"<<endl;
}
else{
  cout<<"queue is not empty"<<endl;
}
  return 0;
}