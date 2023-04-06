// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
#include<bits/stdc++.h>
using namespace std;
const int N=5e+5;
int parent[N];
int max_v[N];
int min_v[N];
int cnt[N];

void make_set(int v){
    parent[v] = v;
    min_v[v] = v;
    max_v[v] = v;
    cnt[v] = 1;
}

int find_set(int v){
    if(v == parent[v]) return v;
    int p = find_set(parent[v]);
    parent[v] = p;
    return p;
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        min_v[a] = min(min_v[a], min_v[b]);
        max_v[a] = max(max_v[a], max_v[b]);
        cnt[a] += cnt[b];
    }
}
void get(int v){
    int p = find_set(v);
    cout << min_v[p] << " " << max_v[p] << " " << cnt[p] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for(int i =1;i<=n;i++) make_set(i);

    for(int i =1; i<=q; i++){
        string c;
        int x, y;
        cin >> c;
        if(c =="union") 
        {
            cin >> x >> y;
            union_set(x,y);
        }
        else {
            cin >> x;
            get(x);
        }
    }


}