#include <iostream>
using namespace std;
int main()
{
  int n;
  int count = 1;
  cin >> n;
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i;
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = n; j >= i; j--)
    {
      cout << j;
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = n; j >= i; j--)
    {
      cout << i;
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = n; j >= i; j--)
    {
      cout << "*";
    }
    cout << endl;
  }

  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << count << " ";
      count++;
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i - j + 1 << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++)
  {
    int space = n - i;
    for (int j = 1; j <= i; j++)
    {
      while (space)
      {
        cout << " ";
        space--;
      }
      cout << "*";
    }
    cout << endl;
  }
  cout << endl;
  
  for (int i = 1; i <= n; i++)
  {
    int space = n - i;
    while (space)
    {
      cout << " ";
      space--;
    }
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }
    int start = i - 1;
    while (start)
    {
      cout << start;
      start--;
    }
    cout << endl;
  }
}