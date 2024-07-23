#include <iostream>
using namespace std;

void printarray(int arr[], int size){
    cout<<"Printing the Array"<<endl;
    for(int i=0;i<size;i++){
      cout<<" "<<arr[i];
    }
    cout<<endl<<"Printing Done"<<endl;
  }
// ABOUT Max element
void getmax(int arr[] , int size){
  int maxi=INT8_MIN;
  for(int i=0;i<size;i++){

    // maxi=max(maxi,arrr[i]);
    //OR
    if(arr[i]>maxi){
      maxi=arr[i];
    } 
  }
  cout<<"MAX ELEMENT IS "<<maxi<<endl;
}
// ABOUT Min element
void getmin(int arr[] , int size){
  int mini=INT8_MAX;
  for(int i=0;i<size;i++){
    mini=min(mini,arr[i]);
    //OR
    // if(arr[i]<mini){
    // mini=arr[i];
    // }
  }
  cout<<"MIN ELEMENT IS "<<mini<<endl;
}


// reverse of array
void revarr(int arr[],int size){
  int start=0;
  int end=size-1;
  cout<<endl<<"********REVERSING THE ARRAY*******"<<endl;
  while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
  }
  }
int main() {
  int n;
  int first[5]={1,2,3,4,5};
  cout<<"Enter size of array"<<endl;
  cin>>n;
  cout<<"Enter elements"<<endl;
  for(int i=0;i<n;i++){
    cin>>first[i];
  }
  getmax(first,5);
  getmin(first,5);
  printarray(first, 5);
  revarr(first,5);
  printarray(first, 5);
  return 0;
}