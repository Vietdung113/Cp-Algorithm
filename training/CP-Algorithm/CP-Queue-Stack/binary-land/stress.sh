#!/bin/bash
# So sanh main.cpp voi main.py tren input ngau nhien.
# main.py da qua 500 ca stress voi brute force nen dung lam chuan duoc.
#
#   ./stress.sh          -- 300 ca
#   ./stress.sh 1000     -- 1000 ca

cd "$(dirname "$0")" || exit 1

ROUNDS=${1:-300}
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT

g++ -std=c++17 -O2 -o sol main.cpp || exit 1

cat > "$TMP/gen.py" <<'PY'
import random, sys
random.seed(int(sys.argv[1]))
n = random.randint(1, 5)
q = random.randint(1, 16)
ops, H = [], 0
for _ in range(q):
    choices = ['add'] if H == 0 else ['add', 'remove', 'path', 'path']
    op = random.choice(choices)
    if op == 'add':
        ops.append('add ' + ''.join(random.choice('01') for _ in range(n))); H += 1
    elif op == 'remove':
        ops.append('remove'); H -= 1
    else:
        ops.append('path %d %d' % (random.randint(1, n), random.randint(1, n)))
print(n, len(ops))
print('\n'.join(ops))
PY

# main.py doc input.txt cua chinh no -- lam ban sao doc tu argv
sed "s|join(dirname(abspath(__file__)), 'input.txt')|sys.argv[1]|" main.py > "$TMP/pysol.py"

for i in $(seq 1 "$ROUNDS"); do
    python3 "$TMP/gen.py" "$i" > "$TMP/tc.txt"
    a=$(./sol < "$TMP/tc.txt")
    b=$(python3 "$TMP/pysol.py" "$TMP/tc.txt")
    if [ "$a" != "$b" ]; then
        echo "=== KHAC NHAU o seed $i ==="
        cat "$TMP/tc.txt"
        echo "--- cpp:"; echo "$a"
        echo "--- py :"; echo "$b"
        exit 1
    fi
done

echo "$ROUNDS/$ROUNDS khop"
