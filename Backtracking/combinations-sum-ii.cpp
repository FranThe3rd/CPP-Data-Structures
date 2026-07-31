#include <iostream>
#include <vector>
#include <algorithm>

/*
    Combination Sum II uses Depth First Search (DFS) with backtracking to
    explore every possible combination of numbers that add up to the target.
    At each recursive call, we have two choices:
    1. Take the current number. Since each number can only be used once,
       we move to the next index (i + 1).
    2. Skip the current number and continue searching with the next index.
    The candidates array is sorted so that duplicate numbers can be skipped.
    This prevents generating the same combination multiple times.
    If the running total equals the target, the current combination is added
    to the result. If the total becomes greater than the target or we run out
    of numbers, that path is abandoned.
    Backtracking is done by removing the last number after returning from the
    recursive call. This restores the previous state so another possible
    combination can be explored.
*/


void dfs(const std::vector<int>& candidates, int target, int i, std::vector<int>& cur, std::vector<std::vector<int>>& res, int total)
{
  if (total == target) {
    res.push_back(cur);
    return;
  }
  if (i >= candidates.size() || total > target) {
    return;
  }
  cur.push_back(candidates[i]);
  dfs(candidates, target, i + 1, cur, res, total + candidates[i]);
  cur.pop_back();
  while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
    i++;
  }
  dfs(candidates, target, i + 1, cur, res, total);
}


std::vector<std::vector<int>> combinationSum2(const std::vector<int>& candidates, int target)
{
  std::vector<std::vector<int>> res;
  std::vector<int> cur;
  dfs(candidates, target, 0, cur, res, 0);
  return res;
}


int main()
{
  std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  
  std::sort(candidates.begin(), candidates.end());
  int target = 8;
  std::vector<std::vector<int>> result = combinationSum2(candidates, target);
  std::cout << "Combinations:\n";
  for (const auto& combination : result) {
    std::cout << "[ ";
    for (int num : combination) {
      std::cout << num << " ";
    }
    std::cout << "]\n";
  }
}
