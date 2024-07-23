#include<iostream>
#include<vector>
using namespace std;
void merge(int arr1[],int n,int arr2[], int m, int arr3[]){
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }

// COPY ELEMENTS OF FIRST ARRAY(REMAINING)
while(i<n){
    arr3[k++]=arr1[i++];
}

// COPY ELEMENTS OF SECOND ARRAY(REMAINING)
while(j<m){
    arr3[k++]=arr2[j++];
}
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

int arr1[4]={1,3,5,7};
int arr2[4]={2,4,6,8};
int arr3[8]={0};

merge(arr1,4,arr2,4,arr3);
cout<<"ARRAY 1 ELEMENTS : ";
print(arr1,4);
cout<<endl<<"ARRAY 2 ELEMENTS : ";
print(arr2,4);
cout<<endl<<"AFTER MERGING ARRAY 1 & 2 : ";
print(arr3,8);

    return 0;
}