#include <vector>
using namespace std;
/*
    We solve this using backtracking (DFS). The idea is to try every cell on the board as a possible starting point for the word. From each cell, we recursively
    explore the four directions (up, down, left, and right), checking whether each
    character matches the next character in the word. Since a cell cannot be reused
    in the same path, we temporarily replace its value with '#' to mark it as
    visited. After exploring all possible paths from that cell, we restore its
    original character so other search paths can use it. This "mark, explore,
    restore" process is the essence of backtracking.
*/


class Solution {
public:
    bool wordSearch(vector<vector<char> > &board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char> > &board, string &word, int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 ||
            r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[i]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        bool found =
                dfs(board, word, r + 1, c, i + 1) || // Down
                dfs(board, word, r - 1, c, i + 1) || // Up
                dfs(board, word, r, c + 1, i + 1) || // Right
                dfs(board, word, r, c - 1, i + 1); // Left

        board[r][c] = temp; // restore

        return found;
    }
};



