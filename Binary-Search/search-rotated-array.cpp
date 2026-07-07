#include <vector>
#include <iostream>



/*
 * https://www.youtube.com/watch?v=4Ik1nCLjwcI  -- Explanation
 * You start of by looking for the minimum rotated sorted array. Like the leetcode questions
 *
 *
 *
 *
 *
 *
 * */ 



// This is essentially searching for minimum sorted array
int searchRotatedArray(std::vector<int> nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;

    if (nums[mid] > nums[r]) {
      l = mid + 1;
    }
    else {
      r = mid;
    }
  }
  int min_index = l;
  // Checking if its sorted
  if (min_index == 0) {
    l = 0;
    r = nums.size() - 1;
  }
  // Checking if its in the left portion
  else if (target >= nums[0] && target <= nums[min_index - 1]) {
    l = 0;
    r = min_index - 1;
  }
  // Checking if its in the right portion
  else {
    l = min_index;
    r = nums.size() - 1;
  }

  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      return mid;
    }
    else if (nums[mid] < target) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  return -1;
}


int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = searchRotatedArray(nums, target);

    if (index != -1) {
        std::cout << "Target found at index: " << index << std::endl;
    }
    else {
        std::cout << "Target not found." << std::endl;
    }

    return 0;
}
