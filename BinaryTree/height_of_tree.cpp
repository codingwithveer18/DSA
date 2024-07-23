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

int height(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int left = height(root->left);
  int right = height(root->right);
  int ans = max(left, right) + 1;

  return ans;
}
int main()
{
  node *root = NULL;
  root = buildtree(root);

  cout << "Height of Binary tree is : " << height(root) << endl;
  return 0;
}