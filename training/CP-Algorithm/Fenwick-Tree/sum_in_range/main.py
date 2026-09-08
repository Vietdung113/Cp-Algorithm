

def add(i, v, n, T):
    while i <= n:
        T[i] += v
        i += lowbit(i)


def lowbit(i): 
    return i & (-i)

def g(i):
    return i - lowbit(i) + 1

def prefix(T, r):
    s = 0
    while r > 0:
        s += T[r]
        r -= lowbit(r)
    return s


def range_sum(T, l, r):
    return prefix(T, r) - prefix(T, l - 1)

if __name__ == '__main__':
    a = [0, 1, 2, 3, 6, 1, 12, 123]
    n = len(a) - 1
    print(a[1:])
    T = [0 for i in range(n + 1)]
    print(T[1:])
    for i in range(1, n + 1):
        L = lowbit(i)
        add(i, a[i], n, T)
    print(T[1:])
    print(range_sum(T, 3, 5))
    
