# https://codeforces.com/problemset/problem/1234/D
import sys
from os.path import join, dirname, abspath
from collections import Counter

# 0: {'a' : 4, 'b': 2, 'c': 1}

def merge(l, r):
    return dict(Counter(l) + Counter(r))


def build(st, s, v, l, r):
    if l == r:
        st[v] = {s[l]: 1}
        return

    mid = (l + r) // 2

    build(st, s, v * 2 + 1, l, mid)
    build(st, s, v * 2 + 2, mid + 1, r)

    st[v] = merge(st[2 * v + 1], st[2*v + 2])

def update(st, node, tl, tr, pos, v):
    if tl == tr:
        st[node] = {v : 1}
        return

    mid = (tl + tr) // 2

    if pos <= mid:
        update(st, node * 2 + 1, tl, mid, pos,  v)
    else:
        update(st, node * 2 + 2, mid + 1, tr, pos, v)

    st[node] = merge(st[node * 2 + 1], st[node * 2 + 2])
    
    
def get(st, node, tl, tr, l, r):
    if l > r:
        return {}

    if tl == l and tr == r:
        return st[node]
    
    mid = (tl + tr) // 2

    left_child = get(st, node * 2 + 1, tl, mid, l, min(r, mid))
    right_child = get(st, node * 2 + 2, mid + 1, tr, max(l, mid + 1), r)

    return merge(left_child, right_child)


if __name__ == '__main__':
    sys.stdin = open(join(dirname(abspath(__file__)), "input.txt"), "r")
    s = input()
    n = len(s)
    st = [0] * len(s) * 4

    build(st, s, 0, 0, n-1)
    
    q = int(input())
    for i in range(q):
        query = input().split()
        if query[0] == '1':
            pos =  int(query[1])
            v = query[2]
            update(st, 0, 0, n - 1, pos - 1, v)
            # print(f"update: {query}\t st: {st}")
        else:
            l, r = query[1:]
            ans = get(st, 0, 0, n-1, int(l) - 1, int(r) - 1)
            print(len(ans))

