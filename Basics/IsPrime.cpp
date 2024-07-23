#include <iostream>
using namespace std;
int main() {
  int n, num;
  bool is_prime=true;
  cout<<"enter any number"<<endl;
  cin>>n;
  if(n<2){
  is_prime = false;
  }
  for(int num=2;num<=n-1;num++){
      if(n % num == 0){
        is_prime= false;
      break;
        }
  }
if(is_prime==true){
  cout<<"prime";}
else{
  cout<<"not prime";}
  return 0;
}