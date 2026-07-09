#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>

/*
 * We use a sliding window with two pointers (l and r) to find the longest substring
 * that can be made up of the same character after replacing at most k characters.
 * As the right pointer expands the window, we count the frequency of each character
 * and keep track of the highest frequency (maxF). If the number of characters that
 * need to be replaced, calculated as (window size - maxF), becomes greater than k,
 * we shrink the window from the left until it becomes valid again. Throughout the
 * process, we update the maximum valid window size, which is the answer.
 */

int longestRepeatingReplacement(std::string s, int k) {
    std::unordered_map<char, int> count;
    int res = 0;
    int l = 0;
    int maxF = 0;

    for (int r = 0; r < s.length(); r++) {
        count[s[r]]++;
        maxF = std::max(maxF, count[s[r]]);
        while ((r - l + 1) - maxF > k) {
            count[s[l]]--;
            l++;
        }
        res = std::max(res, r - l + 1);
    }

    return res;
}

int main() {
    std::string s = "AABABBA";
    int k = 1;
    std::cout << longestRepeatingReplacement(s, k) << std::endl;
}
