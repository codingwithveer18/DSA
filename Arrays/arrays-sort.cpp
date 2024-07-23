#include <iostream>
using namespace std;

void print(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<" "<<arr[i];
  }
}
void sort(int arr[],int size){
  int i=0;
  int j=size-1;
  while(i<j){
    if(arr[i]==0){
      i++;
    }
        if(arr[j]==1){
    j--;
    }
    swap(arr[i], arr[j]);
    i++;j--;
    
    }
  }
int main() {
int first[8]={1,1,0,0,0,0,1,0};
  sort(first, 8);
  print(first,8);
return 0;
}