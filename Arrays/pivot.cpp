#include <iostream>
using namespace std;

int pivot(int arr[],int size){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    
    while(start<end){
        if (arr[mid]>=arr[0]){
            start=mid+1;
        }
        else {
            end=mid;
        }
            mid=start+(end-start)/2;
    }
    return start;
    // return end --> will print the same  answer
}
int binary(int arr[] , int s,  int e, int key){
     int start=s;
    int end=e;
    int mid=start+(end-start)/2;    
    while(start<=end){
        if(key==arr[mid]){
return mid;       
 }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
}
return -1;
}
int findposition(int arr[] , int k,int n){
int p = pivot(arr,n);
if(k>=arr[p] && k<=arr[n-1]){
    // apply binary search to line 2
    return binary(arr,p,n-1,k);
}
else{
        // apply binary search to line 1

    return binary(arr,0,p-1,k);
}
}

int main(){
int arr[9]={5,7,9,11,13,0,1,2,3};

cout<<"ELEMENT AT "<<binary(arr,0,8,5);
}