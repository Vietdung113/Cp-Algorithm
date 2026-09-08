import sys
from os.path import join, dirname, abspath


def add(t, n, i, v):
    while i < n:
        t[i] += v
        i = i | (i + 1)

def prefix(t, i):
    res = 0
    while i >= 0:
        res += t[i]
        i = (i & (i + 1)) - 1
    return res

def sum(t, l, r):
    return prefix(t, r) - prefix(t, l - 1)

if __name__ == '__main__':
    sys.stdin = open(join(dirname(abspath(__file__)), "input.txt"), "r")
    T = int(input())
    for _ in range(T):
        print(f'Case {_ + 1}: ')
        n, q = map(int, input().split())
        arr = list(map(int, input().split()))

        t = [0 for i in range(n)] 

        for i in range(n):
            add(t, n, i , arr[i])
        
        for i in range(q):
            data = list(map(int, input().split()))
            if data[0] == 1:
                add(t, n, data[1], -arr[data[1]])
                print(arr[data[1]])
                arr[data[1]] = 0

            elif data[0] == 2:
                add(t, n, data[1], data[2])
                arr[data[1]] += data[2]

            elif data[0] == 3:
                ans = sum(t, data[1], data[2])
                print(ans)
            
