#include <vector>
#include <iostream>

/*
    Subsets uses Depth First Search (DFS) with backtracking to generate
    every possible subset of a given array. Just remember in this case 
    the array is distinct.
    At each index, we have two choices:
    1. Include the current number in the subset.
       We add nums[i] to the current subset and continue to the next index.
    2. Exclude the current number from the subset.
       We remove the number using backtracking and continue to the next index.
    Every time we reach the end of the array, we have created one complete
    subset, so it is added to the result list.
    Backtracking is done by removing the last added number after exploring
    the path where the number was included. This restores the previous state
    so we can explore the path where the number is excluded.
    For example, with nums = {1,2,3}, the DFS tree explores:

                []
             /      \
          [1]        []
        /    \      /   \
     [1,2]  [1]  [2]    []
       ...
    
    This creates all possible combinations:
    {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}
    Time Complexity: O(2^n)
    Space Complexity: O(n) for the recursion stack.
*/


void dfs(const std::vector<int>& nums, int i, std::vector<int>& subset, std::vector<std::vector<int>>& res) {
  if (i>= nums.size()) {
    res.push_back(subset);
    return;
  }
  subset.push_back(nums[i]);
  dfs(nums,i+1,subset,res);
  subset.pop_back();
  dfs(nums,i+1,subset,res);
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> res;
  std::vector<int> subset;
  dfs(nums,0,subset,res);
  return res;
}



int main() {
  std::vector<int> nums = {1,2,3,4};
  std::vector<std::vector<int>> result = subsets(nums);
  for (const auto& sub : result) {
    std::cout << "[ ";
    for (int x : sub)
      std::cout << x << " ";
    std::cout << "]\n";
  }
}


