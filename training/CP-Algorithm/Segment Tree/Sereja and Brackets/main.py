# https://codeforces.com/contest/380/problem/C
import sys

class Leaf:
    def __init__(self, o, c, p):
        self.o = o
        self.c = c
        self.p = p

def merge(l: Leaf, r: Leaf):
    # ))) (((  ))))((((
    new_pais = min(l.o, r.c)
    new_o = l.o - new_pais + r.o
    new_c = l.c + r.c - new_pais
    new_p = l.p + r.p + new_pais
    return Leaf(new_o, new_c, new_p)

def build(st, s, v, l, r):
    if l == r:
        if s[l] == '(':
            st[v] = Leaf(1, 0, 0)
        else:
            st[v] = Leaf(0, 1, 0)
        return
    mid = (l + r) // 2

    build(st, s, v * 2 + 1, l, mid)
    build(st, s, v * 2 + 2, mid + 1, r)

    st[v] = merge(st[2 * v + 1], st[2 * v + 2])


def query(st, v, tl, tr, l, r):
    if l > r:
        return Leaf(0, 0, 0)

    if l == tl and r == tr:
        return st[v]

    tm = (tl + tr) // 2
    left_child = query(st, 2 * v + 1, tl, tm, l, min(tm, r))
    right_child = query(st, 2 * v + 2, tm + 1, tr, max(tm + 1, l), r)

    return merge(left_child, right_child)


if __name__ == '__main__':
    data = sys.stdin.read().split('\n')
    s = data[0]
    n = len(s)
    st = [Leaf(0, 0, 0)] * (4 * n)
    build(st, s, 0, 0, n - 1)

    m = int(data[1])

    out = []
    for i in range(m):
        l, r = map(int, data[2 + i].split())
        ans = query(st, 0, 0, n - 1, l - 1, r - 1)
        out.append(str(ans.p * 2))

    sys.stdout.write('\n'.join(out) + '\n')
