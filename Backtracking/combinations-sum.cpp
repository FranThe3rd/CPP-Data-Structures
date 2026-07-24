#include <iostream>
#include <vector>



void dfs(int i, std::vector<int>& cur, int total) {
  if (total == target) {
    res.append(cur)
      return;
  }
  if (i>=candidates.size() || total > target) {
    return;
  }
  cur.push_back(candidates[i]);
  dfs(i,cur,total+candidates[i]);
  cur.pop();
  dfs(i+1,cur,total);
}


std::vector<int> combinationSum(std::vector<int> candidates, int target) {
  std::vector<int> res;
  dfs(0,[],0);
  return res;
}



int main() {

  std::vector<int> result = combinationSum();

}



