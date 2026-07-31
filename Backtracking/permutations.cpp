#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * Generates all possible permutations of the given numbers using backtracking.
 * We build one permutation at a time by adding a number that has not already
 * been used in the current permutation. When the permutation reaches the same
 * size as the input, it is complete and stored in the answer. After exploring
 * a choice, we remove the last number (backtrack) so we can try a different
 * number in that position until every possible ordering has been generated.
 */



class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sol;
    void backtrack(vector<int>& nums) {
        if (sol.size() == nums.size()) {
            ans.push_back(sol);
            return;
        }
        for (int x : nums) {
            if (find(sol.begin(), sol.end(), x) == sol.end()) { // Basically means if x not in sol.
                sol.push_back(x);
                backtrack(nums);
                sol.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
