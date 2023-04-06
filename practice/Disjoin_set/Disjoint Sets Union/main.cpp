// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5 +5;
int parent[N];
int n;
void make_set(int a){
    parent[a] = a;
}

int find_set(int a){
    if(parent[a] == a) return a;
    int p = find_set(parent[a]);
    parent[a] = p;
    return p;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
    }
}
void query(int a, int b){
    if (find_set(a) == find_set(b)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(parent, sizeof parent, 0);
    int n, q;
    cin >> n >> q;
    for(int i= 1;i<=n;i++) make_set(i);

    for(int i = 1; i<=q; i++) {
        string c;
        int x,y;
        cin >> c >> x >> y;
        if (c == "union") union_set(x,y);
        else query(x,y);
    }
}