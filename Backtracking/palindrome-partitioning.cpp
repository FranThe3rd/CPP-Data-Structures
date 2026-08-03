#include <iostream>
#include <vector>
#include <string>

/*
 * WHAT IS `end`?
 * end is just the loop counter inside a single for loop — nothing more
 * mysterious than that:
 *     for (int end = start; end < s.size(); end++)
 * Every time dfs(start) is called, this line runs once and declares a
 * brand new `end`, initialized to `start`. That `end` lives entirely
 * inside this one call's stack frame. It is local — C++ allocates fresh
 * memory for it on every single call. No other call can see it or touch
 * it: not the call that invoked this one, and not any call this one
 * invokes.
 * So when this line runs:
 *     dfs(end + 1, s, part);
 * we are NOT modifying the current `end`. We're just reading its value
 * right now to compute a number, and handing that number to a brand new
 * function call. That new call will declare its OWN separate `end`,
 * starting at whatever we passed in. Two different variables, two
 * different homes in memory, that just happen to share a name.
 * WHY IT LOOKS CONFUSING
 * When you trace the recursion, you're watching many of these separate
 * loop counters exist at the same time, each one paused mid-loop at a
 * different value, nested inside each other like open drawers. A given
 * call's `end` only ever changes in one place: `end++`, at the bottom
 * of its own for loop, which runs after the loop body finishes —
 * and the loop body is exactly the four lines below (check palindrome,
 * push, recurse, pop). So `end` never resets mid-loop, and nothing a
 * deeper dfs() call does can reach back and change it. It just sits
 * frozen while dfs(end + 1, ...) runs its entire life — however many
 * iterations, however many levels deep — and only moves forward by one
 * once that deeper call fully returns and pop_back() undoes the choice.
 */
class Solution {
    std::vector<std::vector<std::string>> res;

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::string> part;
        dfs(0, s, part);
        return res;
    }

    void dfs(int start, std::string& s, std::vector<std::string>& part) {
        if (start == s.size()) {
            res.push_back(part);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (isPali(s, start, end)) {

                // Take this palindrome
                part.push_back(s.substr(start, end - start + 1));

                // Continue with the rest
                dfs(end + 1, s, part);

                // Undo choice
                part.pop_back();
            }
        }
    }

    bool isPali(std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    std::string s = "aab";

    auto result = solution.partition(s);

    for (auto& row : result) {
        std::cout << "[ ";
        for (auto& word : row) {
            std::cout << word << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}