#include <bits/stdc++.h>
using namespace std;

// reverse string using recursion
bool palin(string &str, int s, int e)
{
  if (s > e)
  {
    return -1;
  }
  if (str[s] != str[e])
  {
    return false;
  }
  else
  {
    return palin(str, s + 1, e - 1);
  }
}

int main()
{
  string str = "veer";

  bool ispalin = palin(str, 0, str.length() - 1);
  if (ispalin)
  {
    cout << str << " is in palindrome" << endl;
  }
  else
  {
    cout << str << " is not in palindrome" << endl;
  }
  return 0;
}