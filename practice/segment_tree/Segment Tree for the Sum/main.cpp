// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +5;

int a[N];
long long st[4 * N];


void build(int id, int l, int r, int i, int v) {
    if (i < l || r < i) {
        return;
    }
    if (l == r) 
    {
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    build(2*id + 1, l, mid, i ,v);
    build(2*id + 2, mid + 1, r, i, v);

    // operation applied for each segment
    st[id] = st[id*2 + 2] + st[2*id+1];
}

long long get_sum(int id, int l, int r, int u, int v) {
    // cout << id << " " << l << " " << r << " " << u << " " << v << endl;
    if( v < l || r < u) return 0;
    if (u <= l && r <=v ) return st[id];
    int mid = (l + r) / 2;
    return get_sum(id * 2 + 1, l, mid, u, v) + get_sum(2 *id +2, mid + 1, r, u, v);
}

int main() {
    int n,m;
    cin >> n >> m;
    int v;
    for(int i = 0; i < n; i++) {
        cin >> v;
        build(0, 0, n-1, i, v);
    }
    int c,x,y;
    for(int i =1; i<=m ;i++) {
        cin >> c >> x >> y;
        if (c == 1) {
            build(0, 0, n-1, x, y);
        }else{
            cout << get_sum(0, 0, n-1, x, y-1)<<"\n";
        }
    }
}