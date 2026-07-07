#include <iostream>
#include <vector>

/*
This algorithm finds the minimum element in a sorted array that has been
rotated using binary search.

Example:
Original: [1, 2, 3, 4, 5]
Rotated:  [4, 5, 1, 2, 3]

The idea is to compare the middle element with the rightmost element.

- If nums[mid] > nums[r], the minimum must be to the right of mid,
  so we move the left pointer to mid + 1.
- Otherwise, the minimum is at mid or somewhere to the left,
  so we move the right pointer to mid.

We continue shrinking the search range until l == r. At that point,
both pointers are pointing at the smallest element, which we return.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int findMinRotated(std::vector<int> nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
        int mid = (l + r) / 2;

        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return nums[l];
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    std::cout << "Minimum element: " << findMinRotated(nums) << std::endl;

    return 0;
}
