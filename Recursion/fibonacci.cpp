#include <iostream>
using namespace std;
// Using Recursion
int fibb(int n)
{
  if (n < 0)
  {
    return -1;
  }
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return fibb(n - 1) + fibb(n - 2);
}
int main()
{
  int n;
  cout << "Enter value for n" << endl;
  cin >> n;
  cout << "Fibonacci series :" << endl
       << fibb(n);
}