#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
  void solve(vector<int> nums, vector<vector<int>> &ans, int index)
  {
    // base case
    if (index >= nums.size())
    {
      ans.push_back(nums);
      return;
    }
    // for each digit
    for (int i = index; i < nums.size(); i++)
    {
      swap(nums[index], nums[i]);
      solve(nums, ans, index + 1);
      // backtrack for another digit
      swap(nums[index], nums[i]);
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  vector<vector<int>> result = solution.permute(nums);
  cout << "Total Permutations are : " << result.size() << endl;
  for (auto &v : result)
  {
    for (int num : v)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
