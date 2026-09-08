# https://codeforces.com/problemset/problem/339/D
import sys


def build(st, arr, node, l, r, d):
    if l == r:
        st[node] = arr[l]
        return

    mid = (l + r) // 2
    build(st, arr, node * 2 + 1, l, mid, d + 1)
    build(st, arr, node * 2 + 2, mid + 1, r, d + 1)

    if d % 2 != 0:
        st[node] = st[node * 2 + 1] | st[node * 2 + 2]
    else:
        st[node] = st[node * 2 + 1] ^ st[node * 2 + 2]


def update(st, node, l, r, pos, v, d):
    if l == r:
        st[node] = v
        return

    mid = (l + r) // 2

    if pos <= mid:
        update(st, node * 2 + 1, l, mid, pos, v, d + 1)
    else:
        update(st, node * 2 + 2, mid + 1, r, pos, v, d + 1)

    if d % 2 != 0:
        st[node] = st[node * 2 + 1] | st[node * 2 + 2]
    else:
        st[node] = st[node * 2 + 2] ^ st[node * 2 + 1]


def main():
    data = sys.stdin.read().split()
    p = 0
    n = int(data[p]); m = int(data[p + 1]); p += 2
    size = 1 << n
    arr = [int(data[p + i]) for i in range(size)]; p += size

    st = [0] * (4 * size)

    d = 0 if n % 2 == 0 else 1
    build(st, arr, 0, 0, size - 1, d)

    out = []
    for _ in range(m):
        pos = int(data[p]); b = int(data[p + 1]); p += 2
        update(st, 0, 0, size - 1, pos - 1, b, d)
        out.append(st[0])

    sys.stdout.write('\n'.join(map(str, out)) + '\n')


main()
