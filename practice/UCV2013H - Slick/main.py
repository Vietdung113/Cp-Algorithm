import sys
input = sys.stdin.readline

from collections import deque

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs(x, y, g, visited):
    visited[x][y] = True
    q = deque([(x, y)])
    size_stick = 1
    while not len(q) == 0:
        (cx, cy) = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or nx >= len(g) or ny < 0 or ny >= len(g[0]):
                continue
            if visited[nx][ny] or g[nx][ny] == '0':
                continue
            visited[nx][ny] = True
            q.append((nx, ny))
            size_stick += 1
    return size_stick


def dfs(x, y, g, visited):
    visited[x][y] = True
    size_stick = 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= len(g) or ny < 0 or ny >= len(g[0]):
            continue
        if visited[nx][ny] or g[nx][ny] == '0':
            continue
        size_stick += dfs(nx, ny, g, visited)
    return size_stick

        

def solve():
    n, m = map(int, input().split())
    g = [[None] * (m ) for _ in range(n)]
    visited = [[False] * (m ) for _ in range(n)]
    for i in range(n):
        s = input().strip().split()
        for j in range(len(s)):
            g[i][j] = s[j]

    size_sticks = []

    for i in range(n):
        for j in range(m):
            if not visited[i][j] and g[i][j] == '1':
                size_sticks.append(dfs(i, j, g, visited))
    size_sticks.sort()
    print(size_sticks)


solve()