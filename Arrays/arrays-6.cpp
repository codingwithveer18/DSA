#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findPairs(const vector<int>& arr1, int num) {
    vector<vector<int>> ans;
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = i + 1; j < arr1.size(); j++) {
            if (arr1[i] + arr1[j] == num) {
                vector<int> temp;
                temp.push_back(min(arr1[i], arr1[j]));
                temp.push_back(max(arr1[i], arr1[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
void triplesum(int arr[],int num ,int size){
  for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
      for(int k=j+1;k<size;k++){
        if(arr[i]+arr[j]+arr[k]==num){
          cout<<" "<<i<<" "<<j<<" "<<k;
          cout<<endl;
        }
      }
    }
  }
}
int main() {
    int arr1[5] = {2,-3,3,3,-2};
    vector<int> input(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));

    vector<vector<int>> result = findPairs(input, 0);

    for (const auto& pair : result) {
        cout << pair[0] << ", " << pair[1] << endl;
    }
  int arr[5]={1,2,3,4,5};
  triplesum(arr, 5, 8);
    return 0;
}
