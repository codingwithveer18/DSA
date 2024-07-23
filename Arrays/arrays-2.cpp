#include <iostream>
#include <math.h>
using namespace std;

// ABOUT ARRAY SCOPE
void update(int arr[],int size){
  cout<<"ENTERED INTO FUNCTION"<<endl;
  arr[0]=100;
  for(int i=0;i<size;i++){
    cout<<" "<<arr[i];
  }
  cout<<endl<<"GOING BACK TO MAIN BLOCK"<<endl;
}

// PRINTING SUM OF ARRAY ELEMENTS
void sum(int arr[],int size){
  cout<<"ADDING THE ELEMENTS"<<endl;
  int sum=0;
  for(int i=0;i<size;i++){
    sum=sum+arr[i];
  }
  cout<<"SUM IS "<<sum<<endl;
}
int main(){
  int first[5]={1,2,3,4,5};
//   cout<<"Enter size of array"<<endl;
//   cin>>n;
//   cout<<"Enter elements"<<endl;
//   for(int i=0;i<n;i++){
//     cin>>first[i];
//   }
  cout<<endl<<"GOING TO UPDATE FUNCTION"<<endl;
  update(first,5);
  sum(first, 5);
    return 0;
}