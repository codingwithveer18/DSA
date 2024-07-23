#include <bits/stdc++.h>
using namespace std;

// reverse string using recursion
int reversee(string &str, int s, int e)
{
  if (s > e)
  {
    return -1;
  }
  swap(str[s], str[e]);
  s++;
  e--;
  return reversee(str, s, e);
}

int main()
{
  string str = "veer";
  reversee(str, 0, str.length() - 1);
  cout << str;
  return 0;
}