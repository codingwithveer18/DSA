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

void lvlorder(node *root)
{
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
      {
        q.push(temp->left);
      }
      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

void inorder(node *root)
{
  // base case
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void preorder(node *root)
{
  // base case
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(node *root)
{
  // base case
  if (root == NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void buildfromlvlorder(node *&root)
{
  queue<node *> q;
  cout << "enter data for root node" << endl;
  int data;
  cin >> data;
  root = new node(data);
  q.push(root);

  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();
    cout << "enter left node for:" << temp->data << endl;
    int leftdata;
    cin >> leftdata;

    if (leftdata != -1)
    {
      temp->left = new node(leftdata);
      q.push(temp->left);
    }
    cout << "enter right node for:" << temp->data << endl;
    int rightdata;
    cin >> rightdata;

    if (rightdata != -1)
    {
      temp->right = new node(rightdata);
      q.push(temp->right);
    }
  }
}

int main()
{
  node *root = NULL;
  // root = buildtree(root);

  // lvlorder(root);

  // cout << endl;

  // cout << "Inorder traversel :" << endl;
  // inorder(root);

  // cout << endl;

  // cout << "Preorder traversel :" << endl;
  // preorder(root);

  // cout << endl;

  // cout << "Postorder traversel :" << endl;
  // postorder(root);

  buildfromlvlorder(root);
  lvlorder(root);

  return 0;
}