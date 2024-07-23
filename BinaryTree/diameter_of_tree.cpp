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

pair<int, int> diaheight(node *root)
{
  if (root == NULL)
  {
    pair<int, int> p = make_pair(0, 0);
    return p;
  }
  pair<int, int> left = diaheight(root->left);
  pair<int, int> right = diaheight(root->right);

  int op1 = left.first;                     // diameter of left tree
  int op2 = right.first;                    // diameter of right tree
  int op3 = left.second + right.second + 1; // combined height of tree
  pair<int, int> ans;
  ans.first = max(op1, max(op2, op3));
  ans.second = max(left.second, right.second) + 1;

  return ans;
}
int diameter(node *root)
{
  return diaheight(root).first;
}
int main()
{
  node *root = NULL;
  root = buildtree(root);

  cout << "Diameter of Binary tree is : " << diameter(root) << endl;
  return 0;
}