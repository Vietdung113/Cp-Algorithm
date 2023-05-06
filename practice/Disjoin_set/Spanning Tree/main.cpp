// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int parent[N];
int sz[N];
struct edge {
    int u, v, w;
    bool operator<(edge &other) {
        return w < other.w;
    }
};

vector<edge> E;

int find_set(int v) {
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if (sz[u] < sz[v]) swap(u,v);
    parent[v] = u;
    sz[u] += 1;
}

int main() {
    int n,m;
    int u,v,w;
    cin >> n >> m;
    for(int i =1; i<=m;i++) {
        cin >>  u>>v >> w;
        E.push_back({u, v, w});
        E.push_back({v,u,w});
    }
    for(int i = 1; i<=n; i++) {
        parent[i] =i;
        sz[i] = 1;
    }
    long long ans = 0;
    sort(E.begin(), E.end());
    for(auto e: E) {
        if(find_set(e.u) != find_set(e.v)) {
            ans += e.w;
            // cout << e.u << " " << e.v << " " << e.w << " " << ans << endl;
            union_set(e.u, e.v);
        }
   }
    cout << ans;
}