#include <vector>
#include <iostream>

/*
 * Binary Search:
 * Search for a target value in a sorted array by repeatedly
 * checking the middle element.
 *
 * - If the target is smaller than the middle value,
 *   search the left half.
 * - If the target is larger than the middle value,
 *   search the right half.
 * - Repeat until the target is found or the search range is empty.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

int binarySearch(std::vector<int> nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        }
        else if (nums[mid] > target) {
            r = mid - 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int result = binarySearch(nums, target);
    if (result != -1) {
        std::cout << "Found " << target
                  << " at index " << result << std::endl;
    }
    else {
        std::cout << target << " not found." << std::endl;
    }
    return 0;
}
