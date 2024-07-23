#include <iostream>
#include <math.h>
using namespace std;

void printarray(int arr[], int size){
    cout<<"Printing the Array"<<endl;
    for(int i=0;i<size;i++){
      cout<<" "<<arr[i];
    }
    cout<<endl<<"Printing Done"<<endl;
  }
// swapping alternate elemets of array
void swap(int arr[] , int size){
  cout<<"SWAPPING ALTERNATE"<<endl;
  for(int i=0;i<size;i+=2){
    if(i+1<size){
      swap(arr[i], arr[i+1]);
    }
  }
}
// finding unique element in array
void unique(int arr[] , int size){
  int ans=0;
  for(int i=0;i<size;i++){
    ans=ans^arr[i];
  }
  cout<<"Unique Element is : "<<ans<<endl;
}

int main(){
  int n;
  int first[n];
  cout<<"Enter size of array"<<endl;
  cin>>n;
  cout<<"Enter elements"<<endl;
  for(int i=0;i<n;i++){
    cin>>first[i];
  }
  swap(first, n);
  printarray(first, n);
  unique(first, n);
return 0;
  
}