// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int p[N];
int sz[N];
int parent[N];

int find_set(int v){
    if( v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x==y) return;
    parent[x] = y;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i<=n;i++) {
        parent[i] = i ;
    }
    int x;
    for(int i =1; i<=n ;i ++){
        cin >> x;
        int p = find_set(x);
        cout << p << "\n";
        if(p == n) {
            union_set(n, 1);
        }else{
            union_set(p, p+1);
        }
    }
}
