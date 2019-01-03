/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size(), c = board[0].size();
        
        if (word == "") return true;
        if (r == 0 || c == 0) return false;
        
        for (unsigned int i = 0; i < r; i++) {
            for (unsigned int j = 0; j < c; j++) {
                if (board[i][j] == word[0]) {
                    int m = i, n = j;
                    if (isFound(board, word, i, j, 0))
                        return true;
                }
            }
        }
        
        return false;
    }
private:
    int r, c;
    bool isFound(vector<vector<char> > &board, string &word, int i, int j, int k) {
        if (i < 0 || i >= r || j < 0 || j >= c||
            board[i][j] == '*' || word[k] != board[i][j]) {
            return false;
        }
        
        if (k == word.size() - 1) 
            return true;
        
        char temp = board[i][j];
        board[i][j] = '*';      // used
        if (isFound(board, word, i-1, j, k+1) ||
            isFound(board, word, i+1, j, k+1) ||
            isFound(board, word, i, j-1, k+1) ||
            isFound(board, word, i, j+1, k+1)) {
            return true;
        }
        board[i][j] = temp;
        return false;
    }
};