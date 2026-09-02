import sys
input = sys.stdin.readline

N = int(input())
a = list(map(int, input().split()))

def count_groups():
    cnt = 1
    groups = []
    for i in range(N - 1):
        if a[i] == a[i + 1]:
            cnt +=1 
        else:
            groups.append(cnt)
            cnt = 1
    groups.append(cnt)
    return groups
        

def solve():
    groups = count_groups()
    ans = 0
    for i in range(len(groups) - 1):
        ans = max(ans, 2 * min(groups[i], groups[i + 1]))

    return ans

print(solve())

    