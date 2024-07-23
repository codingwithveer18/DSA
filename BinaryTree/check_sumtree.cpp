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

pair<bool, int> isSumTreefast(node *root)
{
  // base case
  if (root == NULL)
  {
    pair<bool, int> p = make_pair(true, 0);
    return p;
  }
  // for not checking leaf node
  if (root->left == NULL && root->right == NULL)
  {
    pair<bool, int> p = make_pair(true, root->data);
    return p;
  }
  // check for left tree
  pair<bool, int> left = isSumTreefast(root->left);
  // check for right tree
  pair<bool, int> right = isSumTreefast(root->right);

  bool leftans = left.first;
  bool rightans = right.first;

  bool sum = root->data == left.second + right.second;

  pair<bool, int> ans;

  if (leftans && rightans && sum)
  {
    ans.first = true;
    ans.second = 2 * root->data;
  }
  else
  {
    ans.first = false;
  }
  return ans;
}
bool isSumTree(node *root)
{
  return isSumTreefast(root).first;
}
int main()
{
  node *root = NULL;
  root = buildtree(root);
  cout << "Checking if Binary tree is SumTree or not : ";
  if (isSumTree(root) == 1)
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  };
  return 0;
}