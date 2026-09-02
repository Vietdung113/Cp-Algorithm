
board = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        def check(pos):
            if pos == 81:
                return True
            r, c = pos // 9, pos % 9
            val = board[r][c]
            if val == ".":
                return check(pos + 1)
            box_id = (r // 3) * 3 + c // 3
            if val in rows[r] or val in cols[c] or val in boxes[box_id]:
                return False
            rows[r].add(val)
            cols[c].add(val)
            boxes[box_id].add(val)
            return check(pos + 1)

        return check(0)