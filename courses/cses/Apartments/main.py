import sys

input = sys.stdin.readline


def solve(a, b, k):
    a = sorted(a)
    b = sorted(b)
    i = 0
    ans = 0
    for p in a:
        while i < len(b) and p - k > b[i]:
            i += 1
        if i < len(b) and p - k <= b[i] <= p + k:
            ans += 1
            i += 1
    return ans


if __name__ == "__main__":
    n, m, k = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))

    ans = solve(a, b, k)
    print(ans)
