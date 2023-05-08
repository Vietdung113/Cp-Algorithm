//https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
int parent[N];
int sz[N];
int mx[N];
 
int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    mx[x] = max(mx[x], mx[y]);
    parent[y] = x;
}
 
int get_nearest(int x) {
    x = find_set(x);
    return mx[x];
 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n + 1; i++) {
        parent[i] = i;
        sz[i] = 1;
        mx[i] = i;
    }
    
    string c;
    int x;
    while(m--){
        cin >> c;
        cin >> x;
        if (c == "?") {
            int p = get_nearest(x);
            if (p > n) {
                cout << "-1" << endl;
            }else{
                cout << p << endl;
            }
        }
        else if (c == "-") {
            union_set(x, x + 1);
        }
    }
}