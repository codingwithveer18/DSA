#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k = 2;
  vector<int> arr = {-8, 2, 3, -6, 10};
  int n = arr.size();

  deque<int> dq;
  vector<int> ans;
  // processing for first k window's elements
  for (int i = 0; i < k; i++)
  {
    if (arr[i] < 0)
    {
      dq.push_back(i);
    }
  }
  // storing answer
  if (dq.size() > 0)
  {
    ans.push_back(arr[dq.front()]);
  }
  else
  {
    ans.push_back(0);
  }

  // processing for rest of the elements

  for (int i = k; i < n; i++)
  {
    // removal of previos and addition of next to maintain the  cycle of window size

    if (!dq.empty() && (i - dq.front()) >= k)
    {
      dq.pop_front();
    }

    // addition
    if (arr[i] < 0)
    {
      dq.push_back(i);
    }

    // storing ans
    if (dq.size() > 0)
    {
      ans.push_back(arr[dq.front()]);
    }
    else
    {
      ans.push_back(0);
    }
  }
  cout << "First Negative integers in every window of size k are :";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}