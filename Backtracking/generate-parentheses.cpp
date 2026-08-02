#include <iostream>
#include <vector>
#include <string>

/*
 * We need to generate every valid combination of n pairs of parentheses.
 * Example:
 * n = 3
 * We must use:
 *   3 '(' characters
 *   3 ')' characters
 * Since each pair contributes two characters, every completed answer
 * will have a length of 2 * n (6 characters when n = 3).
 * We build one string one character at a time using backtracking.
 * At every step we have two possible choices:
 * 1. Add '('
 *    We can only do this if we have used fewer than n opening
 *    parentheses.
 * 2. Add ')'
 *    We can only do this if there are more '(' than ')' already
 *    in the current string. Otherwise the string would become invalid.
 * Whenever the current string reaches a length of 2 * n, we know
 * we've used all parentheses, so we save that completed string.
 */

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        std::vector<char> sol;
        backtrack(n, 0, 0, sol, ans);
        return ans;
    }

private:
    void backtrack(int n, int open, int close, std::vector<char> &sol, std::vector<std::string> &ans) {
        if (sol.size() == 2 * n) {
            ans.push_back(std::string(sol.begin(), sol.end()));
            return;
        }
        if (open < n) {
            sol.push_back('(');
            backtrack(n, open + 1, close, sol, ans);
            sol.pop_back();
        }
        if (open > close) {
            sol.push_back(')');
            backtrack(n, open, close + 1, sol, ans);
            sol.pop_back();
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::string> ans = solution.generateParenthesis(3);
    for (const std::string &s: ans) {
        std::cout << s << '\n';
    }
    return 0;
}

