import sys
from os.path import dirname, join, abspath


MOD = 1000000007


def build_step(pre, curr):
    n = len(pre)
    s = []
    for c in range(n):
        m = [1 if curr[d] == pre[c] and abs(d-c) <= 1 else 0 for d in range(n)]
        s.append(m)
    return s

def step_sparse(pre, curr):
    """Bang mot-buoc duoi hai dang thua, dung thang tu hai hang - khong qua ma tran.

    rows[c] = cac cot d di tu c den duoc.  cols[d] = cac cot c di den d duoc.
    Moi danh sach co nhieu nhat 3 phan tu.
    """
    n = len(pre)
    rows = [[] for _ in range(n)]
    cols = [[] for _ in range(n)]
    for c in range(n):
        col = pre[c]
        lo = c - 1 if c else 0
        hi = c + 2 if c + 2 <= n else n
        for d in range(lo, hi):
            if curr[d] == col:
                rows[c].append(d)
                cols[d].append(c)
    return rows, cols

def mul_right_sparse(a, b_cols):
    """a o b, voi b la ma tran 0/1 da chuyen sang dang cot."""
    return [[sum([row[k] for k in cd]) % MOD for cd in b_cols] for row in a]

def mul_left_sparse(a_rows, b):
    """a o b, voi a la ma tran 0/1 da chuyen sang dang dong."""
    n = len(b)
    out = []
    for ks in a_rows:
        if not ks:
            out.append([0] * n)
        elif len(ks) == 1:
            out.append(b[ks[0]][:])
        else:
            acc = b[ks[0]]
            for k in ks[1:]:
                acc = [x + y for x, y in zip(acc, b[k])]
            out.append([x % MOD for x in acc])
    return out

def calc_p(prev_p, s):
    """Giu lai cho test.py: nhan hai ma tran day du."""
    n = len(s)
    cols = [[k for k in range(n) if s[k][d]] for d in range(n)]
    return mul_right_sparse(prev_p, cols)

def identity(n):
    return [[1 if i == j else 0 for j in range(n)] for i in range(n)]

def top_p(stack, n):
    if not stack:
        return identity(n)
    return stack[-1][1]

def add(prev_line, line, stack_in):
    n = len(line)
    curr_line = [int(i) for i in line]
    if prev_line != []:
        s_rows, s_cols = step_sparse(prev_line, curr_line)
        p = mul_right_sparse(top_p(stack_in, n), s_cols)
        stack_in.append((s_rows, p))

    return curr_line, stack_in

def query(c, d, stack_in, stack_out, n):
    p_i = top_p(stack_in, n)
    p_o = top_p(stack_out, n)
    ans = 0
    for i in range(n):
        ans += p_o[c][i] * p_i[i][d]
        ans = ans % 1000000007
    return ans


def remove(stack_in, stack_out, n, prev_line):
    if len(stack_out) > 0:
        stack_out.pop()
        return prev_line

    # stack_out == []
    if len(stack_in) == 0 and len(stack_out) == 0:
        prev_line = []
        return prev_line

    
    while len(stack_in) > 0:
        s_rows, _ = stack_in[-1]
        curr_p = top_p(stack_out, n)
        p = mul_left_sparse(s_rows, curr_p)
        stack_out.append((s_rows, p))
        stack_in.pop()
    
    stack_out.pop()
    return prev_line


if __name__ == '__main__':
    input_path = join(dirname(abspath(__file__)), 'input.txt')
    sys.stdin = open(input_path, 'r')
    n, q = map(int, input().strip().split())

    prev_line = []
    stack_in = [] 
    stack_out = []

    for i in range(q):
        cmd = input().strip().split()
        if cmd[0] == 'add':
            prev_line, stack_in = add(prev_line, cmd[-1], stack_in)
        if cmd[0] == 'path':
            c, d = map(int, cmd[1:])
            print(query(c - 1, d - 1, stack_in, stack_out, n))
        if cmd[0] == 'remove':
            prev_line = remove(stack_in, stack_out, n, prev_line)
