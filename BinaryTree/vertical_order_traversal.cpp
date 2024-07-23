#include <bits/stdc++.h>
using namespace std;

class node
{

public:
  int data;
  node *left;
  node *right;

  node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

node *buildtree(node *root)
{

  cout << "enter the data" << endl;
  int data;
  cin >> data;
  root = new node(data);
  if (data == -1)
  {
    return NULL;
  }
  cout << "enter data for left of " << data << endl;
  root->left = buildtree(root->left);
  cout << "enter data for right of " << data << endl;
  root->right = buildtree(root->right);
  return root;
}

vector<int> vertical(node *root)
{
  map<int, map<int, vector<int>>> nodes;
  queue<pair<node *, pair<int, int>>> q;
  vector<int> ans;

  if (root == NULL)
  {
    return ans;
  }
  q.push(make_pair(root, make_pair(0, 0)));
  while (!q.empty())
  {

    pair<node *, pair<int, int>> temp = q.front();
    q.pop();
    node *frontNode = temp.first;
    int hori = temp.second.first;
    int lvl = temp.second.second;

    nodes[hori][lvl].push_back(frontNode->data);

    if (frontNode->left)
    {
      q.push(make_pair(frontNode->left, make_pair(hori - 1, lvl + 1)));
    }
    if (frontNode->right)
    {
      q.push(make_pair(frontNode->right, make_pair(hori + 1, lvl + 1)));
    }
  }
  for (auto i : nodes)
  {
    for (auto j : i.second)
    {
      for (auto k : j.second)
      {
        ans.push_back(k);
      }
    }
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return ans;
}
int main()
{
  node *root = NULL;
  root = buildtree(root);

  cout << "Printing Data for Vertical Traversal" << endl;
  vertical(root);
  return 0;
}

// 1 2 -1 -1 3 4 -1 -1 5 -1 -1