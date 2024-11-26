import sys
input = sys.stdin.readline


def solve(p, x):
    p = sorted(p, reverse=True)
    i, j = 0, len(p) - 1
    ans = 0
    while i <= j:
        if p[i] + p[j] <= x:
            ans += 1
            i += 1
            j -= 1
        else:
            ans += 1
            i += 1
        # print("ans: ", ans, " i: ", i, " j: ", j)
    return ans

if __name__ == "__main__":
    n, x = map(int, input().split(" "))
    p = list(map(int, input().split(" ")))

    ans = solve(p, x)
    print(ans)