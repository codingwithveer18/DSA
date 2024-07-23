#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans,
               string mapping[]) {

        // base case - index out of bound
        if (index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        // now take out first digit. ex - 2 in "23"
        int number = digit[index] - '0';
        // - 0 is done in order to convert the ASCII value of digits[index] into
        // desired number;
        string value = mapping[number];
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index + 1, ans, mapping);
            // now after executing the above 2 statement, we need to perform pop
            // operation too
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        int index = 0;
        if (digits.length() == 0) {
            return ans;
        }
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};

int main() {
    Solution sol;
    string digits = "34";
    vector<string> combinations = sol.letterCombinations(digits);
    cout << "Letter combinations for " << digits << " are:\n";
    for (const auto &combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}
