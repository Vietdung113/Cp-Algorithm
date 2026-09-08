# https://www.spoj.com/problems/MATSUM/
import sys
from os.path import join, dirname, abspath


def make_grid(n):
    return [[0 for i in range(n)] for j in range(n)]

def add(grid, n, x, y, v):
    while x < n:
        i = y 
        while i < n:
            grid[x][i] += v
            i = i | (i + 1)
        x = x | (x + 1)
    return grid

def set_v(grid, a, n, x, y, v):
    new_v = v - a[x][y]
    a[x][y] = v
    grid  = add(grid, n, x, y, new_v)
    return grid, a

def prefix_sum(grid, x, y):
    res = 0
    while x >= 0:
        j = y
        while j >= 0:
           res += grid[x][j] 
           j = (j & (j + 1)) - 1
        x = (x & (x + 1)) - 1
    return res

def sum(grid, x1, y1, x2, y2):
    return prefix_sum(grid, x2, y2) + prefix_sum(grid, x1 - 1, y1 - 1) - prefix_sum(grid, x1 - 1, y2) - prefix_sum(grid, x2, y1 - 1)

if __name__ == '__main__':
    sys.stdin = open(join(dirname(abspath(__file__)), "input.txt"), "r")
    t = int(input())
    for _ in range(t):
        n = int(input())
        grid = make_grid(n)
        a = make_grid(n)
        data = [1]
        while data[0] != 'END':
            data = input().split()
            if data[0] == 'SET':
                x, y, v = map(int, data[1:])
                grid, a = set_v(grid, a, n, x, y, v)
            elif data[0] == 'SUM':
                x1, y1, x2, y2 = map(int, data[1:])
                ans = sum(grid, x1, y1, x2, y2)
                print(ans)
            
