"""Test cac ham con cua main.py.

Chay:  python3 test.py
"""
import main

MOD = 1000000007
FAILED = []


def check(name, got, want):
    if got == want:
        print("  OK   ", name)
    else:
        print("  SAI  ", name)
        print("        got :", got)
        print("        want:", want)
        FAILED.append(name)


# ---------------------------------------------------------------- build_step
# Luoi 3x3 tinh tay:
#     hang 1:  0 0 1
#     hang 2:  0 1 1
#     hang 3:  1 1 1
print("build_step")

A = main.build_step([0, 0, 1], [0, 1, 1])       # hang 1 -> hang 2
B = main.build_step([0, 1, 1], [1, 1, 1])       # hang 2 -> hang 3

check("A (hang1->hang2)", A, [[1, 0, 0],
                              [1, 0, 0],
                              [0, 1, 1]])

check("B (hang2->hang3)", B, [[0, 0, 0],
                              [1, 1, 1],
                              [0, 1, 1]])

# bien: 1 cot duy nhat
check("N=1 cung mau",  main.build_step([1], [1]), [[1]])
check("N=1 khac mau",  main.build_step([1], [0]), [[0]])


# ------------------------------------------------------------------- calc_p
print("calc_p")

I3 = main.identity(3)

check("A o B (hang1->hang3)", main.calc_p(A, B), [[0, 0, 0],
                                                  [0, 0, 0],
                                                  [1, 2, 2]])
check("I o A == A", main.calc_p(I3, A), A)
check("A o I == A", main.calc_p(A, I3), A)


# -------------------------------------------------------------------- top_p
print("top_p")

check("stack rong -> I", main.top_p([], 3), I3)
check("stack co phan tu -> P dinh", main.top_p([("s0", "p0"), ("s1", "p1")], 3), "p1")


# ---------------------------------------------------------------------- add
print("add  (bat bien: so phan tu queue == so hang - 1)")

st = []
pl = []
pl, st = main.add(pl, "001", st)
check("1 hang -> 0 phan tu", len(st), 0)

pl, st = main.add(pl, "011", st)
check("2 hang -> 1 phan tu", len(st), 1)

pl, st = main.add(pl, "111", st)
check("3 hang -> 2 phan tu", len(st), 2)

check("tich queue == bang hang1->hang3", main.top_p(st, 3), [[0, 0, 0],
                                                             [0, 0, 0],
                                                             [1, 2, 2]])


# -------------------------------------------------------------------- query
print("query  (chua co remove nen stack_out luon rong)")

# luoi 1 hang: chi c == d moi co duong
st1, pl1 = [], []
pl1, st1 = main.add(pl1, "001", st1)
check("1 hang, c==d", main.query(1, 1, st1, [], 3), 1)
check("1 hang, c!=d", main.query(0, 2, st1, [], 3), 0)

# luoi 3 hang, doi chieu voi bang A o B
check("3 hang, (2,2) -> 2", main.query(2, 2, st, [], 3), 2)
check("3 hang, (2,0) -> 1", main.query(2, 0, st, [], 3), 1)
check("3 hang, (0,0) -> 0", main.query(0, 0, st, [], 3), 0)


# ------------------------------------------------------------------- remove
# Chua viet. Khi viet xong, bo comment va kiem tra:
#
#   Luoi 3 hang [001, 011, 111], queue = [S2, S3].
#   Sau 1 lan remove: luoi con [011, 111], dap an phai bang S3 = B.
#
# st2, pl2 = [], []
# for line in ["001", "011", "111"]:
#     pl2, st2 = main.add(pl2, line, st2)
# ... goi remove ...
# check("sau remove, tich == B", <tich cua queue>, B)


print()
if FAILED:
    print(len(FAILED), "test SAI:", ", ".join(FAILED))
else:
    print("Tat ca test PASS")
