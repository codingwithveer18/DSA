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
void traverseLeft(node *root, vector<int> &res)
{
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
  {
    return;
  }
  res.push_back(root->data);
  if (root->left)
  {
    traverseLeft(root->left, res);
  }
  else
  {
    traverseLeft(root->right, res);
  }
}
void traverseLeaf(node *root, vector<int> &res)
{
  if (root == NULL)
  {
    return;
  }
  if (root->left == NULL && root->right == NULL)
  {
    res.push_back(root->data);
    return;
  }
  traverseLeaf(root->left, res);

  traverseLeaf(root->right, res);
}
void traverseRight(node *root, vector<int> &res)
{
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
  {
    return;
  }
  if (root->right)
  {
    traverseRight(root->right, res);
  }
  else
  {
    traverseRight(root->left, res);
  }

  // wapas going
  res.push_back(root->data);
}
vector<int> boundary(node *root)
{
  vector<int> res;
  if (root == NULL)
  {
    return res;
  }
  res.push_back(root->data);

  // for left traverse
  traverseLeft(root->left, res);

  // for leaf traverse
  // Either in left subtree
  traverseLeaf(root->left, res);
  // or in right subtree
  traverseLeaf(root->right, res);

  // for Right Traversal
  traverseRight(root->right, res);

  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
  }
  cout<<endl;
  return res;
}
int main()
{
  node *root = NULL;
  root = buildtree(root);

  cout << "Printing Data for Boundary Traversal" << endl;
  boundary(root);
  return 0;
}

// 1 2 -1 -1 3 4 -1 -1 5 -1 -1