
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int parent[N];
int extra_exp[N];
int sz[N];

void make_set(int v){
    parent[v] = v;
    extra_exp[v] = 0;
    sz[v] = 1;
}

int find_set(int v){
    if (v == parent[v]) return v;
    return find_set(parent[v]);
}

void add_point(int v, int p){
    extra_exp[find_set(v)] += p;
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    if( sz[x] < sz[y]) swap(x,y);
    sz[x] += sz[y];
    parent[y] = x;
    extra_exp[y] -= extra_exp[x];
}

int get_point(int v){
    if (v == parent[v]) return extra_exp[v];
    return extra_exp[v] + get_point(parent[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n ;i++) make_set(i);
    string c;
    int x,y;
    while(m--){
        cin >> c;
        if(c == "add"){
            cin >> x >> y;
            add_point(x, y);
        }
        if (c == "join") {
            cin >> x >> y;
            union_set(x,y);
        }
        if ( c == "get") {
            cin >> x;
            cout <<  get_point(x) << endl;
        }
    }
}