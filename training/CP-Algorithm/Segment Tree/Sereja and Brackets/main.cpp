// https://codeforces.com/contest/380/problem/C
#include <bits/stdc++.h>
using namespace std;

struct Leaf {
    int o, c, p;
};

Leaf merge(const Leaf &l, const Leaf &r) {
    int new_pairs = min(l.o, r.c);
    Leaf res;
    res.o = l.o - new_pairs + r.o;
    res.c = l.c + r.c - new_pairs;
    res.p = l.p + r.p + new_pairs;
    return res;
}

vector<Leaf> st;
string s;

void build(int v, int l, int r) {
    if (l == r) {
        st[v] = (s[l] == '(') ? Leaf{1, 0, 0} : Leaf{0, 1, 0};
        return;
    }
    int mid = (l + r) / 2;
    build(v * 2 + 1, l, mid);
    build(v * 2 + 2, mid + 1, r);
    st[v] = merge(st[v * 2 + 1], st[v * 2 + 2]);
}

Leaf query(int v, int tl, int tr, int l, int r) {
    if (l > r) return Leaf{0, 0, 0};
    if (l == tl && r == tr) return st[v];
    int tm = (tl + tr) / 2;
    Leaf left_child = query(v * 2 + 1, tl, tm, l, min(tm, r));
    Leaf right_child = query(v * 2 + 2, tm + 1, tr, max(tm + 1, l), r);
    return merge(left_child, right_child);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int n = s.size();
    st.assign(4 * n, Leaf{0, 0, 0});
    build(0, 0, n - 1);

    int m;
    cin >> m;

    string out;
    out.reserve(m * 7);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        Leaf ans = query(0, 0, n - 1, l - 1, r - 1);
        out += to_string(ans.p * 2);
        out += '\n';
    }
    cout << out;

    return 0;
}
