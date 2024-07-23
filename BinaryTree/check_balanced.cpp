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

pair<bool, int> isBalanced(node *root)
{
  // base case
  if (root == NULL)
  {
    pair<bool, int> p = make_pair(true, 0);
    return p;
  }
  // check for left tree
  pair<bool, int> left = isBalanced(root->left);
  // check for right tree
  pair<bool, int> right = isBalanced(root->right);

  bool leftans = left.first;
  bool rightans = right.first;

  bool diff = abs(left.second - right.second) <= 1;

  pair<bool, int> ans;
  ans.second = max(left.second, right.second) + 1;

  if (leftans && rightans && diff)
  {
    ans.first = true;
  }
  else
  {
    ans.first = false;
  }
  return ans;
}
bool isBalancedBT(node *root)
{
  return isBalanced(root).first;
}
int main()
{
  node *root = NULL;
  root = buildtree(root);
  cout << "Checking if Binary tree is Balanced or not : ";
  if (isBalancedBT(root) == 1)
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  };
  return 0;
}