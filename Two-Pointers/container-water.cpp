#include <vector>
#include <iostream>
#include <algorithm>


/*
 * 
 *
 *
 *
 * */

int maxArea(std::vector<int> heights) {
  int res = 0;
  int l = 0;
  int r = heights.size() - 1;
  while (l < r) {
    int area = (r - l) * std::min(heights[l], heights[r]);
    res = std::max(res, area);

    if (heights[l] < heights[r]) {
      l++;
    } else {
      r--;
    }
  }

  return res;
}

int main() {
  std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int result = maxArea(heights);
  std::cout << "Max area: " << result << std::endl;
  return 0;
}
