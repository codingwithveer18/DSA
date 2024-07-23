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
vector<int> zigzag(node *root)
{
  vector<int> res;
  if (root == NULL)
  {
    return res;
  }
  queue<node *> q;
  q.push(root);

  bool leftToRight = true;
  while (!q.empty())
  {
    int size = q.size();
    vector<int> temp(size);

    for (int i = 0; i < size; i++)
    {
      node *frontNode = q.front();
      q.pop();

      int index = leftToRight ? i : size - i - 1;
      temp[index] = frontNode->data;

      if (frontNode->left)
      {
        q.push(frontNode->left);
      }
      if (frontNode->right)
      {
        q.push(frontNode->right);
      }
    }
    leftToRight = !leftToRight;
    for (auto i : temp)
    {
      res.push_back(i);
      cout<<i<<" ";
    }
     cout<<endl;
  }
  return res;
}
int main()
{
  node *root = NULL;
  root = buildtree(root);

cout<<"Printing Data in ZigZag Traversal"<<endl;
  zigzag(root);
  return 0;
}

// 1 2 -1 -1 3 4 -1 -1 5 -1 -1