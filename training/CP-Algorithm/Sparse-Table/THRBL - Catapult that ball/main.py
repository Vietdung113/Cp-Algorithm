# https://www.spoj.com/problems/THRBL/
import sys

from os.path import join, dirname, abspath


def build(arr):
    n = len(arr)
    k = n.bit_length() - 1
    st = [[-1 for i in range(n)] for j in range(k +1)]
    st[0] = arr
    for i in range(1, k + 1):
        for j in range(0, n - (1<<i) + 1):
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))])
    return st


def query(arr, st, l, r):
    k = (r - l + 1).bit_length() - 1
    max_between = max(st[k][l], st[k][r - (1<<k) + 1])
    if arr[l] >= max_between:
        return 1
    return 0


if __name__ == '__main__':
    try:
        input_path = join(dirname(abspath(__file__)), 'input.txt')
        sys.stdin = open(input_path, 'r')
    except Exception as e:
        pass
    n, m = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))

    st = build(arr)
    ans = 0
    for i in range(m):
        l, r = map(int, input().strip().split())
        # start with 0
        ans += query(arr, st, l - 1, r - 2)
    print(ans)
    

