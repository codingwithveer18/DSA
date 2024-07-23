#include <iostream>
#include <math.h>
using namespace std;
// REVERSING THE INTEGER
void rev(int num){
  cout<<"REVERSE OF GIVEN NO. is : ";
  int ans=0;
    while(num!=0){
  if((ans>INT8_MAX) || (ans<INT8_MIN)){
    cout<<"INVALID";
  }
    ans=(ans*10)+(num%10);
    num=num/10;
  }
  cout<<ans<<endl;
}

// Convert to binary and finding the compliment
void binary(int x){
  int m=x;
  int mask=0;
  if(x==0){
    cout<<1;
  }
  else{
  while(m!=0){
    mask=(mask<<1) | 1;
    m=m>>1;
  }
  cout<<"Compliment is ";
  int ans= (~x) & mask; 
  cout<<ans<<endl;}
}
int main (){
  int x,y;
  cout<<"ENTER AN INTERGER TO BE REVERSED"<<endl;
  cin>>x;
  rev(x);
  cout<<"ENTER ANY NUMBER TO FIND ITS COMPLIMENT"<<endl;
  cin>>y;
  binary(y);
  return 0;
}