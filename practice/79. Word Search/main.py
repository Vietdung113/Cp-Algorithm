board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"

from typing import List


class Solution:

    def backtrack(self, r, c, board, word, idx):
        if idx == len(word):
            return True
        if r < 0 or r >= len(board) or c < 0 or c >= len(board[0]) or board[r][c] != word[idx]:
            return False

        temp = board[r][c]
        board[r][c] = "#"

        found = self.backtrack(r + 1, c, board, word, idx + 1) or \
                self.backtrack(r - 1, c, board, word, idx + 1) or \
                self.backtrack(r, c + 1, board, word, idx + 1) or \
                self.backtrack(r, c - 1, board, word, idx + 1)

        board[r][c] = temp
        return found

    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.backtrack(i, j, board, word, 0):
                    return True
                
        return False