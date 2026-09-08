# https://codeforces.com/contest/380/problem/C
import sys
from os.path import join, dirname, abspath


def check(t):
    c = 0
    ans = len(t)
    for w in t:
        if w == "(":
            c += 1
        else:
            c -= 1
        if c < 0:
            ans -= 1
            c = 0
    ans -= c

    return ans



if __name__ == '__main__':
    sys.stdin = open(join(dirname(abspath(__file__)), "input.txt"), "r")
    s = input()
    print(s)
    n = len(s)
    m = int(input())
    for i in range(m):
        l, r = map(int, input().split())
        x = check(s[l-1: r])
        print(x)


