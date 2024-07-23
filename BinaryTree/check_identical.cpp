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

bool identicalTrees(node *root1, node *root2) {
  if (root1 == NULL && root2 == NULL) {
    return true;
  }
  if (root1 == NULL && root2 != NULL) {
    return false;
  }
  if (root1 != NULL && root2 == NULL) {
    return false;
  }

  bool left = identicalTrees(root1->left, root2->left);
  bool right = identicalTrees(root1->right, root2->right);

  bool val = root1->data == root2->data;

  if (left && right && val) {
    return true;
  } else {
    return false;
  }
}
int main()
{
  node *root1 = NULL;
  node *root2 = NULL;
  root1 = buildtree(root1);
  root2 = buildtree(root2);
  cout << "Checking if Binary tree is Identical or not : ";
  if (identicalTrees(root1,root2) == 1)
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  };
  return 0;
}