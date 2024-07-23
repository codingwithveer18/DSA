#include <iostream>
#include <math.h>
using namespace std;

// Power of 2
int power(int x){
if(x>0){
  for(int i=0;i<31;i++){
    int ans =pow(2,i);
    if(ans==x){
      return ans;
    }
}
}
return 0 ;
  }

// Linear Search
int search(int arr[],int size,int k){
  for(int i=0;i<size;i++){
    if(arr[i]==k){
      return 1;
    }
}
    return 0;
}
int main(){
  int key,y;
  int first[5]={1,2,3,4,5};
  cout<<"ENTER ELEMENT TO BE SEARCHED IN ARRAY "<<endl;
  cin>>key;\
  int a=search(first,5,key);
  if(a!=0){
  cout<<"ELEMENT FOUND AT INDEX: "<<a<<endl;
  }
  else{
    cout<<"Not found"<<endl;
  }
  cout<<"ENTER ANY NUMBER TO CHECK IT CAN BE REPRESENTED INTO POWER OF 2"<<endl;
  cin>>y;
  int b=power(y);
  if(b!=0){
  cout<<"YES"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
return 0;
}