# https://www.codechef.com/problems/MSTICK
import sys
import os

from os.path import join, dirname, abspath

def _build_max_table(n: int, arr: list):
    k = n.bit_length() - 1
    st = [[-1 for i in range(n)] for j in range(k + 1)]
    st[0] = arr
    for i in range(1, k+1):
        for j in range(n - (1<<i) + 1):
            st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i - 1))])
    return st


def _build_min_table(n: int, arr: list):
    k = n.bit_length() - 1
    st = [[-1 for i in range(n)] for j in range(k + 1)]
    st[0] = arr
    for i in range(1, k+1):
        for j in range(n - (1<<i) + 1):
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))])
    return st



def build(n: int, arr: list):
    st_max = _build_max_table(n, arr)
    st_min = _build_min_table(n, arr)
    return st_max, st_min

def query(n, arr, st_max, st_min, l, r):
    previous_length = l.bit_length() - 1
    current_length = (r - l + 1).bit_length() - 1
    post_length = (n - r - 1).bit_length() - 1


    t_min = min(st_min[current_length][l], st_min[current_length][r - (1<< current_length) + 1])
    if l > 0:
        previous_max = max(st_max[previous_length][0], st_max[previous_length][l - (1<<previous_length)])
    else:
        previous_max = float('-inf')
    if r < n - 1:
        post_max = max(st_max[post_length][r + 1], st_max[post_length][n - (1<<post_length)])
    else:
        post_max = float('-inf')

    max_lr = max(st_max[current_length][l], st_max[current_length][r - (1 << current_length) + 1]) 
    

    current_max = max(t_min, (t_min + (max_lr - t_min) / 2))
    
    return float(max(previous_max + t_min, post_max + t_min, current_max))


if __name__ == '__main__':
    # Local: doc input.txt neu no ton tai VA khong rong.
    # Judge: khong co file (hoac co ma rong) -> dung stdin that.
    _p = join(dirname(abspath(__file__)), 'input.txt')
    if os.path.isfile(_p) and os.path.getsize(_p) > 0:
        sys.stdin = open(_p)
    n = int(input())
    arr = list(map(int, input().strip().split()))
    
    st_max, st_min = build(n, arr)

    q = int(input())
    for i in range(q):
        l, r = map(int, input().strip().split())
        print(query(n, arr, st_max, st_min, l, r))

