#include <bits/stdc++.h>
using namespace std;

void sort(int *arr, int size)
{
  if (size == 0 || size == 1)
  {
    return;
  }
  for (int i = 0; i < size - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
    }
  }
  sort(arr, size - 1);
}
int main()
{
  int arr[5] = {2, 8, 5, 0, 6};
  sort(arr, 5);
  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}