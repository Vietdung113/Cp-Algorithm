import sys

from os.path import join, dirname, abspath

def build(arr):
    # print(arr)
    n = len(arr)

    k = n.bit_length() - 1
    st = [[float('inf') for i in range(n)] for j in range(k + 1)]
    st[0] = arr
    for i in range(1, k + 1):
        for j in range(0, n - (1<<i) + 1):
            st[i][j] = min(st[i-1][j] , st[i-1][j + (1 << (i - 1))])
    # print(st)
    return st

def query(st, l, r):
    k = (r - l + 1).bit_length() - 1
    # r - 2 ^ k + 1
    return min(st[k][l], st[k][r - (1 << k) + 1])
        

if __name__ == '__main__':
    try:
        input_path = join(dirname(abspath(__file__)), 'input.txt')
        sys.stdin = open(input_path, 'r')
    except Exception as e:
        pass
    n = int(input())
    # print(f"n: {n}")
    arr = list(map(int, input().strip().split()))
    q = int(input())
    

    st = build(arr)

    for i in range(q):
        l, r = map(int, input().strip().split())
        # print(f"query: {l} {r}")
        print(query(st, l , r))
