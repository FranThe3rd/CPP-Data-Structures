#include <vector>
#include <iostream>

/*
 * 
 *
 *
 *
 * */


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


