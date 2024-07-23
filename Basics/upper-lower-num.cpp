#include <iostream>
using namespace std;
int main() {
  char ch;
  cout << "enter any character or number" << endl;
  cin >> ch;
  if (isupper(ch)) {
    cout << "Entered character " << ch << " is in Uppercase" << endl;
  } else if (islower(ch)) {
    cout << "Entered character " << ch << " is in lowercase" << endl;
  } else {
    cout << "entered character is a number";
  }
  return 0;
}