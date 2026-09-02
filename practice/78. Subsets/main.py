
from typing import List
num = [1,2,3]

class Solution:

    def __init__(self):
        self.ans = []
        self.res = []

    def backtrack(self, start, nums):
        self.ans.append(self.res.copy())
        for i in range(start, len(nums)):
            self.res.append(nums[i])
            self.backtrack(i + 1, nums)
            self.res.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.backtrack(0, nums)
        return self.ans


print(Solution().subsets(num))