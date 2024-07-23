#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
private:
  bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> &visited)
  {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  void solve(vector<vector<int>> &m, int n, vector<string> &ans, string path, vector<vector<int>> &visited, int x, int y)
  {
    // base case
    if (x == n - 1 && y == n - 1)
    {
      ans.push_back(path);
      return;
    }
    // visited index
    visited[x][y] = 1;

    // 4 choices - D/L/R/U

    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, m, n, visited))
    {
      path.push_back('D');
      solve(m, n, ans, path, visited, newx, newy);
      path.pop_back();
    }
    // left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, m, n, visited))
    {
      path.push_back('L');
      solve(m, n, ans, path, visited, newx, newy);
      path.pop_back();
    }
    // Up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, m, n, visited))
    {
      path.push_back('U');
      solve(m, n, ans, path, visited, newx, newy);
      path.pop_back();
    }
    // Right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, m, n, visited))
    {
      path.push_back('R');
      solve(m, n, ans, path, visited, newx, newy);
      path.pop_back();
    }

    // backtracked index
    visited[x][y] = 0;
  }

public:
  vector<string> findPath(vector<vector<int>> &m, int n)
  {
    vector<string> ans;
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
    {
      return ans;
    }
    string path = "";
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(m, n, ans, path, visited, srcx, srcy);
    sort(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  vector<vector<int>> maze = {{1, 0, 0, 0},
                              {1, 0, 0, 1},
                              {1, 1, 0, 0},
                              {0, 1, 1, 1}};
  Solution sol;
  vector<string> result = sol.findPath(maze, 4);
  for (auto path : result)
  {
    cout << path << endl;
  }
  return 0;
}
