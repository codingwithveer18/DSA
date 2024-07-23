#include <iostream>
using namespace std;
int main() {
  int n , i=1, sum=0;
  cout<<"Enter a positive number"<<endl;
  cin>>n;
  while(i<=n){
    sum=sum+i;
    cout<<i<<" ";
    i++;
  }
    cout<<endl<<"sum of above numbers is :"<<sum<<endl;
    
  int m=0;
  int add=0;
  while(m<=n){
    add=add+m;
    m=m+2;
  }
  cout<<"Sum of even numbers in it is :"<<add<<endl;

  int o=1;
  int tot=0;
  while(o<=n){
    tot=tot+o;
    o=o+2;
  }
  cout<<"Sum of odd numbers in it is :"<<tot;
}