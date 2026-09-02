from typing import List
n = 4
k = 2

class Solution:
    def __init__(self):
        self.res =[]
        self.ans = []

    def backtrack(self, start, n, k):
        if len(self.res) == k:
            self.ans.append(self.res.copy())
            return
        for i in range(start, n + 1):
            self.res.append(i)
            self.backtrack(i + 1, n, k)
            self.res.pop()

    def combine(self, n: int, k: int) -> List[List[int]]:
        self.backtrack(1, n, k)
        return self.ans

            
                


