#include <iostream>
using namespace std;



int main()
{
  int n, num = 1;
  long fact = 1.0;
  cout << "Enter any no." << endl;
  cin >> n;
  if (n < 0)
  {
    cout << "invalid for factorial";
  }
  else
  {
    for (int num = 1; num <= n; num++)
    {
      fact = fact * num;
    }
    cout << "Factorial of " << n << " is :" << fact;
  }

  return 0;
}