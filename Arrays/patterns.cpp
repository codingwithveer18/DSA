#include <iostream>
using namespace std;
int main() {
  int n, count=1;
  cout<<"Enter a number for rows and columns "<<endl;
  cin>>n;
  // HERE i will deal with no. of rows
  for(int i=1;i<=n;i++){
    // Here j will deal with no. of column to print "*"
    for(int j=1;j<=n;j++)
      {
        cout<<"* ";
      }
    cout<<endl;
  }
  cout<<endl;
 // Here k will deal with no. of column to print number in same order 
  for(int i=1;i<=n;i++){
    for(int k=1;k<=n;k++)
      {
        cout<<i<<" ";
      }
  cout<<endl;
    }
    cout<<endl;
// Here l will deal with no. of column to print number in alternative order
for(int i=1;i<=n;i++){
    for(int l=1;l<=n;l++)
      {
        cout<<l<<" ";
      }
  cout<<endl;
    }
  cout<<endl;
  
// Here p will deal with no. of column to print number in reverse order
for(int i=1;i<=n;i++){
    for(int p=1;p<=n;p++)
      {
        cout<<n-p+1<<" ";
      }
  cout<<endl;
    }
  cout<<endl;

  // Here q will deal with no. of column to print counting
for(int i=1;i<=n;i++){
    for(int q=1;q<=n;q++)
      {
        cout<<count<<" ";
        count++;
          }
  cout<<endl;
    }
}