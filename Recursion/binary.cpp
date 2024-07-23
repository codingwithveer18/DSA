#include <iostream>
using namespace std;

// using recursion
int recurb(int arr[], int s, int e, int key)
{
  if (s > e)
  {
    return -1;
  }
  int mid = (s + ((e - s) / 2));
  if (arr[mid] == key)
  {
    return mid;
  }
  if (key > mid)
  {
    return recurb(arr, mid + 1, e, key);
  }
  else
  {
    return recurb(arr, s, mid-1, key);
  }
}

int binary(int arr[], int size, int key)
{
  int start = 0;
  int end = size - 1;
  int mid = (start + ((end - start) / 2));
  while (start <= end)
  {
    if (arr[mid] == key)
    {
      return mid;
    }
    if (key > mid)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = (start + ((end - start) / 2));
  }
  return -1;
}
int firstoccur(int arr[], int size, int key)
{
  int start = 0;
  int end = size - 1;
  int first;
  int mid = start + (end - start) / 2;
  while (start <= end)
  {
    if (arr[mid] == key)
    {
      first = mid;
      end = mid - 1;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = (start + ((end - start) / 2));
  }
  return first;
}
int lastoccur(int arr[], int size, int key)
{
  int start = 0;
  int end = size - 1;
  int last;
  int mid = start + (end - start) / 2;
  while (start <= end)
  {
    if (arr[mid] == key)
    {
      last = mid;
      start = mid + 1;
    }
    else if (key > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = (start + ((end - start) / 2));
  }
  return last;
}
int main()
{
  int first[5] = {1, 2, 3, 4, 5};
  int newarr[7] = {1, 2, 3, 3, 3, 4, 5};
  int a = binary(first, 5, 3);
  int b = firstoccur(newarr, 7, 3);
  int c = lastoccur(newarr, 7, 3);
  if (a != -1)
  {
    cout << a << endl;
  }
  if (b != -1)
  {
    cout << b << endl;
  }
  if (c != -1)
  {
    cout << c << endl;
  }
  cout<<"Index of target in array : "<<recurb(first,0,5,5)<<endl;
  return 0;
}