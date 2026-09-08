// https://codeforces.com/problemset/problem/1234/D
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> tree; // bitmask of letters present in the range

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = 1 << (s[tl] - 'a');
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
    tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
}

void update(int v, int tl, int tr, int pos, char c) {
    if (tl == tr) {
        tree[v] = 1 << (c - 'a');
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(v * 2 + 1, tl, tm, pos, c);
    else update(v * 2 + 2, tm + 1, tr, pos, c);
    tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    return query(v * 2 + 1, tl, tm, l, min(r, tm)) |
           query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();
    tree.assign(4 * n, 0);
    build(0, 0, n - 1);

    int q;
    cin >> q;

    string out;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            update(0, 0, n - 1, pos - 1, c);
        } else {
            int l, r;
            cin >> l >> r;
            int mask = query(0, 0, n - 1, l - 1, r - 1);
            out += to_string(__builtin_popcount(mask));
            out += '\n';
        }
    }
    cout << out;

    return 0;
}
