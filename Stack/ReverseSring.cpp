#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str = "veer";
  stack<char> s;
  for (int i = 0; i < str.length(); i++)
  {
    // char ch = str[i];
    // s.push(ch);
    s.push(str[i]);
  }
  string ans = "";
  while (!s.empty())
  {
    char ch = s.top();
    ans.push_back(ch);
    s.pop();
  }

  cout << "Reversed String is : " << ans;
  return 0;
}