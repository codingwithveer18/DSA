#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    void solve(vector<int> nums, vector<int> output, int index,vector<vector<int>>& ans) {
        // base case- when index is traversed
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        // exclude- not pushing that number on index
        solve(nums, output, index + 1, ans);
        // include-pushing that number on index into output and again calling function with updated values
        int ele = nums[index];
        output.push_back(ele);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> subsets = sol.subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout<<"Powerset count :"<<subsets.size();

    return 0;
}
