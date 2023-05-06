//https://codeforces.com/group/u0I8m6kvs3/contest/353626/problem/B
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int sz[N];


void make_set(int n){
    for(int i =1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find_set(int x){
    if (x == parent[x]) return x;
    parent[x] = find_set(parent[x]);
    return parent[x];
}


void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if (sz[x] < sz[y]) swap(x,y);
    parent[y] = x;
    sz[x] += sz[y];
}


int main() {
    int n;
    cin >> n;
    make_set(n);
    int x, y, c;
    for(int i =1; i<=n;i++){
        cin >> x >> y >> c;
        if(c==1){
            union_set(x,y);
        }
        if(c==2){
            // cout << x << " " << find_set(x) << " " << y << " " << find_set(y) << endl;
            if(find_set(x) == find_set(y)){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }

    }

}