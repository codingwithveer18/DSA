    #include <iostream>
using namespace std;

// Array intersection
void inter(int arr1[], int arr2[],int m,int n){
  
  int i=0,j=0;
  while(i<n){
    if(arr1[i]==arr2[j]){
    cout<<arr1[i]<<endl;
      i++;j++;
    }
    if(arr1[i]<arr2[j]){
      i++;
    }
    
    if(arr1[i]>arr2[j]){
      j++;
    }
  }
}
int main(){
  int first[5]={1,2,3,4,5};
  int second[6]={2,3,4,4,7,40};
  inter(first , second , 5 , 6);
return 0;
}