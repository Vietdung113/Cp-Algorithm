// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int st[4 * N];

void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    if (l == r) {
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 +1, l, mid, i, v);
    update(id * 2 + 2, mid +1, r, i, v);

    st[id] = min(st[id * 2 +1] , st[id*2 + 2]);
}

int get_min(int id, int l, int r, int u, int v) {
    if(v < l || r < u) return INT_MAX;
    if(u <=l && r <=v ) return st[id];

    int mid = (l + r) / 2;
    return min( get_min(id * 2 + 1 ,l, mid, u, v) , get_min(id * 2 + 2, mid +1, r, u, v));
}

int main() {
    int n ,m;
    cin >> n >> m;
    int v;
    for(int i = 0;i<n;i++){
        cin >> v;
        update(0, 0, n-1, i, v);
    }
    int c,x,y;
    for(int i = 0;i<m;i++) {
        cin >> c >> x >> y;
        if (c == 1) {
            update(0, 0, n-1, x, y);
        }
        else{
            cout << get_min(0, 0, n-1, x, y-1) << "\n";
        }
    }
}