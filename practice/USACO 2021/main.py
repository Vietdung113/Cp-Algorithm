import sys
input = sys.stdin.readline

N, K, L = map(int, input().split())
c = list(map(int, input().split()))
c.sort(reverse=True)


def check(h):
    cnt = 0
    need = 0
    for i in range(h):
        if c[i] < h:
            if h - c[i] > K:
                return False
            cnt += 1
            need += h - c[i]
            
    if cnt == 0:
        return True
    if need <= K * min(L, cnt):
        return True
    return False


def solve():
    l, r = 0, N 
    while l < r :
        mid = (l + r + 1) // 2
        # print(l, r, mid, check(mid))
        if check(mid):
            l = mid 
        else:
            r = mid - 1
    return l


print(solve())