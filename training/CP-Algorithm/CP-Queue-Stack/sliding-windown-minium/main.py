import sys
from os.path import dirname, join, abspath


from collections import deque

def solve(arr, k):
    q = deque()
    min_idx = []

    for i in range(len(arr)):
        while q and arr[q[-1]] >= arr[i]:
            q.pop()

        if q and i - q[0] >= k :
            q.popleft()

        q.append(i)

        if i >= k - 1:
            min_idx.append(q[0])
    ans = 0
    for i in min_idx:
        ans ^= arr[i]
    return ans

# [3, 0, 1, 8, 2, 4, 7, 6]
#
# i: 0 q : 0
# i: 1 q: 1
# i: 2 q: 1, 2
# i: 3 q: 1, 2, 3
# i: 4 q: 1, 2, 4
# i: 5 q: 1, 2, 4, 5
# i: 6 q: 2, 4, 5, 6
# i: 7 q 2, 4, 5, 7
                
if __name__ == '__main__':
    input_path = join(dirname(abspath(__file__)), 'input.txt')
    sys.stdin = open(input_path, 'r')
    n, k = map(int, input().strip().split())
    x, a, b, c = map(int, input().strip().split())
    arr = [x] * n 
    for i in range(1, n):
        arr[i] = (a * arr[i-1] + b) % c
    print(solve(arr, k))

