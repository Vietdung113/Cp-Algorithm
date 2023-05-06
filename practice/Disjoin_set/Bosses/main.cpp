// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
pair<int, int> parent[N];

void union_set(int x, int y){
    parent[x] = {y, 1};
}
pair<int,int> count_superior(int v){
    if(parent[v].first == v) return {v, 0};
    pair<int, int> k = count_superior(parent[v].first);
    parent[v].first = k.first;
    parent[v].second += k.second;
    return parent[v];
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <=n ;i++){
        parent[i] = {i, 0};
    }
    int c,x,y;
    while(m--) {
        cin >> c ;
        if(c == 1) {
            cin >> x >> y;
            union_set(x,y);
        }else{
            cin >> x;
            pair<int,int> b = count_superior(x);
            cout << b.second << "\n";
        }
    }
}