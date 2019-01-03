'''
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
'''

class Solution:
    def isFound(self, board, word, i, j):
        if len(word) == 0:
            return True
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] == '*' or word[0] != board[i][j]:
            return False
        
        temp = board[i][j]
        board[i][j] = '*'
        
        if self.isFound(board, word[1:], i-1, j) or self.isFound(board, word[1:], i+1, j) or self.isFound(board, word[1:], i, j-1) or self.isFound(board, word[1:], i, j+1):
            return True
        
        board[i][j] = temp
        return False
    
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        r = len(board)
        c = len(board[0])
        
        if r == 0 or c == 0:
            return False
        
        if len(word) == 0:
            return True
        
        for i in range(r):
            for j in range(c):
                if board[i][j] == word[0]:
                    if self.isFound(board, word, i, j):
                        return True
        
        return False