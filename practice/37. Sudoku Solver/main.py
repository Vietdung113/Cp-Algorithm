board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]


from typing import List


class Solution:

    def backtrack(self, r, c, board, rows, cols, boxes):
        # Tìm ô trống tiếp theo
        while r < 9:
            if board[r][c] == '.':
                break
            c += 1
            if c == 9:
                c = 0
                r += 1
        else:
            return True  # Đã điền hết -> thành công

        box_id = (r // 3) * 3 + c // 3
        next_r, next_c = (r, c + 1) if c + 1 < 9 else (r + 1, 0)

        for num in '123456789':
            if num not in rows[r] and num not in cols[c] and num not in boxes[box_id]:
                board[r][c] = num
                rows[r].add(num)
                cols[c].add(num)
                boxes[box_id].add(num)

                if self.backtrack(next_r, next_c, board, rows, cols, boxes):
                    return True

                board[r][c] = '.'
                rows[r].remove(num)
                cols[c].remove(num)
                boxes[box_id].remove(num)
        return False

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == ".":
                    continue
                rows[r].add(val)
                cols[c].add(val)
                box_id = (r // 3) * 3 + c // 3
                boxes[box_id].add(val)

        self.backtrack(0, 0, board, rows, cols, boxes)

        print(board)

        

