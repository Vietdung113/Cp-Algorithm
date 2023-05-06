// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int parent[N];
int sz[N];

int find_set(int v) {
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x==y) return;
    if (sz[x] < sz[y]) swap(x,y);
    parent[y] = x;
    sz[x] += sz[y];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, q;
    set<int> joined;
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
        parent[i] =  i;
        sz[i] = 1;
        joined.insert(i);
    }

    int x,y,t;
    int pos;
    while(q--) {
        cin >> t >> x >> y;
        if(t == 1){
            union_set(x,y);
        }
        if( t==2 ){
            pos = *joined.lower_bound(x);
            while(pos < y){
                joined.erase(pos);
                union_set(pos, pos+1);
                pos = *joined.lower_bound(pos);
            }
        }
        if (t==3){
            if(find_set(x) == find_set(y)) {
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
       
}