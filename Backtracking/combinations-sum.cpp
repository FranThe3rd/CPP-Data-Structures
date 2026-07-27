#include <iostream>
#include <vector>


/*
    Combination Sum uses Depth First Search (DFS) with backtracking to
    explore every possible combination of numbers that add up to the
    target. At each recursive call we have two choices: include the
    current number (which means we stay at the same index because it can
    be reused), or skip it and move to the next index. If the running
    total equals the target, the current combination is stored. If the
    total becomes larger than the target or we run out of numbers, that
    path is abandoned. Backtracking is done by removing the last number
    after returning from recursion so the next choice starts with the
    previous state.
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
  dfs(candidates, target, i, cur, res, total + candidates[i]);
  cur.pop_back();
  dfs(candidates, target, i + 1, cur, res, total);
}


std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target)
{
  std::vector<std::vector<int>> res;
  std::vector<int> cur;
  dfs(candidates, target, 0, cur, res, 0);
  return res;
}

int main()
{
  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  std::vector<std::vector<int>> result = combinationSum(candidates, target);
  std::cout << "Combinations:\n";
  for (const auto& combination : result) {
    std::cout << "[ ";
    for (int num : combination) {
      std::cout << num << " ";
    }
    std::cout << "]\n";
  }
}