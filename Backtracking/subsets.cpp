#include <vector>
#include <iostream>

/**/








std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> res;
  std::vector<int> subset;
  dfs(nums,0,subset,res)

}



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


