#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int size){
  for (int i = 0; i < size; i++)
  {
    cout<<arr[i]<<" ";
  }
  
}
// Initialise an array
bool linear(int key, int size, int arr[])
{
  int i = 0;
  while (i < size)
  {
    if (key == arr[i])
    {
      return true;
      break;
    }
    i++;
  }
  return false;
}
void maxi(int arr[], int size)
{
  int e = INT_MIN;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > e)
    {
      e = arr[i];
    }
  }
  cout << "MAX ELEMENT IS " << e;
}
void even(int arr[], int size)
{
  cout << "even elements are :"
       << " ";
  for (int i = 0; i < size; i++)
  {

    if (arr[i] % 2 == 0)
    {
      cout << arr[i] << " ";
    }
  }
}
void reverse(int arr[], int size)
{
  int i = 0;
  int j = size-1;
  cout << "reserved elements are :"
       << " ";
  // for (int i = size - 1; i >= 0; i--)
  // {
  //   cout << arr[i] << " ";
  // }
  while (i < j)
  {
    swap(arr[i],arr[j]);
    i++;
    j--;
  }
  print(arr,size);
}

int main()
{
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int key = 8;
  // cout << linear(8, 6, arr);
  // maxi(arr, 6);
  // even(arr, 6);
  reverse(arr, 6);
  return 0;
}
