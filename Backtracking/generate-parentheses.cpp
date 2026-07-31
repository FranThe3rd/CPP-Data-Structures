#include <iostream>
#include <vector>
#include <string>

/*
 * We want to generate all combinatiions of a well formed parantheses.
 * So whenever we have a variable like n = 3, that means
 * we will have 3 pairs of parentheses. Which means we will
 * have 3 open parantheses, and 3 closes or ((())).
 *
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

