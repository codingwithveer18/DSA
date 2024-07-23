#include <iostream>
using namespace std;

int main() {
  double temp;
  cout<<"Enter the temperature in celsius"<<endl;
  cin>>temp;
  cout<<"temperature in kelvin :"<<temp+273<<"K"<<endl<<"temperature in Fahrenheit :"<<(1.8*temp)+32<<"F";
}