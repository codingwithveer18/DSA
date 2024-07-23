#include<iostream>
using namespace std;

// converting char to lowercase
char lower(char ch){
  if(ch>='a' && ch<='z'){
    return ch;
  }
  else{
    char temp = ch - 'A' + 'a';
    return temp;
  }
}
// converting char to Uppercase
char upper(char ch){
  if(ch>='A' && ch<='Z'){
    return ch;
  }
  else{
    char temp = ch - 'a' + 'A';
    return temp;
  }
}

bool palindrome(char a[],int n){
int s=0;
int e=n-1;  
while(s<=e){
  
  if(lower(a[s])!= lower(a[e])){
    return 0; //false
  }
  else{
    s++;e--;
  }
}
  return 1; ///true
}
void reverse(char name[], int count){
  int s=0;
  int e=count-1;
  while(s<e){
    swap(name[s++], name[e--]);
  }
}

int getlength(char name[]){
  int count =0;
  for(int i=0;name[i]!='\0';i++){
    count++;
  }
  return count;
}

int main(){
char name[10];

cout<<"Enter you name"<<endl; 
cin>>name;
cout<<"Your name is : "<<name;
 int len = getlength(name);
cout<<endl<<"Length of your name :"<<len;
reverse(name, len);
cout<<endl<<"Your Reversed name is : "<<name;
cout<<endl<<"Checking Palindrome : "<<palindrome(name,len);
cout<<endl<<"To Lowercase : "<<lower('B');
cout<<endl<<"To Uppercase : "<<upper('b');

    return 0; 
}