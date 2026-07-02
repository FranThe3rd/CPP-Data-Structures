#include <vector>
#include <iostream>

/*
 * So we are trying to solve two sum if the array is sorted.
 * So we use a two pointer. We set the current equal to the 
 * array at the left and right side. Then check if its bigger or lower than the target.
 * If it is less than the target we have to move towards the right so we increase the left pointer, 
 * and opposite for the right pointer.
 * If we found a solution we just return the vector. If not we return an empty vector.
 * */

std::vector<int> twoSum2(std::vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r) {
        int current = numbers[l] + numbers[r];

        if (current > target) {
            r--;
        }
        else if (current < target) {
            l++;
        }
        else {
            return {l + 1, r + 1};
        }
    }

    return {};
}

int main() {
    int target = 3;
    std::vector<int> numbers = {1, 2, 3, 4};

    std::vector<int> result = twoSum2(numbers, target);

    for (int num : result) {
        std::cout << num << " ";
    }
}
