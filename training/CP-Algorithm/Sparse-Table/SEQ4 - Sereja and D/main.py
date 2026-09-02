# Sereja and D  (SPOJ SEQ4 / CodeChef SEAD)
# https://www.codechef.com/problems/SEAD
import sys
import os
from bisect import bisect_right
from os.path import join, dirname, abspath


def build_max(arr):
    """Sparse table cho max. Copy tu Matchsticks."""
    n = len(arr)
    if n == 0:
        return []
    K = n.bit_length()
    st = [arr[:]]
    for i in range(1, K):
        prev, half = st[i - 1], 1 << (i - 1)
        st.append([max(prev[j], prev[j + half])
                   for j in range(n - (1 << i) + 1)])
    return st


def range_max(st, l, r):
    """max(g[l..r]) inclusive. Tra ve -1 neu doan rong (l > r)."""
    if l > r:
        return -1
    i = (r - l + 1).bit_length() - 1
    return max(st[i][l], st[i][r - (1 << i) + 1])


def solve(a, st, n, t, d):
    k = bisect_right(a, t) - 1        # index 0-based cua phan tu cuoi <= t
    if k < 0:
        return 0                      # khong co phan tu nao <= t

    # TODO: tim i nho nhat (0-based) sao cho range_max(st, i, k-1) <= d
    #       -> in ra i + 1  (de bai 1-based)
    #
    #   F(i) = range_max(st, i, k-1) khong tang khi i tang  -> binary search
    #   lo = 0, hi = k
    #   doan rong (i == k) luon hop le vi range_max tra -1
    # i = k                             # <-- thay bang binary search cua ban
    lo, hi = 0, k
    
    while lo < hi:
        mid = (lo + hi) // 2
        if range_max(st, mid, k - 1) <= d:
            hi = mid
        else:
            lo = mid + 1

    return lo + 1


if __name__ == '__main__':
    
    # Chi doc input.txt khi CHINH TA bat bien CP_LOCAL.
    # Judge khong bao gio co bien nay -> luon dung stdin that.
    # (Khong dung try/except: CodeChef co /mnt/input.txt cua rieng no,
    #  open() thanh cong nen except khong bat duoc -> EOFError.)
    if os.environ.get('CP_LOCAL'):
        sys.stdin = open(join(dirname(abspath(__file__)), 'input.txt'), 'r')

    n = int(input())
    a = list(map(int, input().strip().split()))
    m = int(input())

    g = [a[i + 1] - a[i] for i in range(n - 1)]
    st = build_max(g)

    for _ in range(m):
        t, d = map(int, input().strip().split())
        print(solve(a, st, n, t, d))
