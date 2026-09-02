import sys
from os.path import join, dirname, abspath


def make_set(n):
    return [i for i in range(0, n+1)]

def union(a, b, parents):
    a = find(a, parents)
    b = find(b, parents)
    if a != b:
        parents[a] = b

def find(v, parents):
    if v == parents[v]:
        return v
    parents[v] = find(parents[v], parents)
    return parents[v]


if __name__ == '__main__':
    try:
        input_path = join(dirname(abspath(__file__)), "input.txt")
        sys.stdin = open(input_path, 'r')
    except Exception as e:
        pass

    n = int(input())
    remove_pairs = []

    parents = make_set(n)
    for i in range(n - 1):
        u, v = map(int, input().strip().split())
        if find(u, parents) != find(v, parents):
            union(u, v, parents)
        else:
            remove_pairs.append((u,v))
    add_pairs = []

    for i in range(1, n):
        if find(i, parents) != find(i+1, parents):
            union(i, i +1, parents)
            add_pairs.append((i, i+1))
    
    print(len(add_pairs))
    max_day_remove = len(remove_pairs)
    for d in range(len(add_pairs)):
        u, v = add_pairs[d]
        if d < max_day_remove:
            i, j = remove_pairs[d]
            print(f'{i} {j} {u} {v}')
            



    

