import sys

from collections import deque

input = sys.stdin.readline


def bfs(start, g, visited):
    visited[start] = True
    q = deque([start])
    while q:
        u = q.popleft()
        for v in g[u]:
            if visited[v]:
                continue
            visited[v] = True
            q.append(v)

def solve():
    n, m = map(int, input().split())
    g = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    ans = 0
    visited = [False] * (n + 1)   
    for i in range(1, n + 1):
        if visited[i]:
            continue
        bfs(i, g, visited)
        ans += 1
    print(ans)

solve()