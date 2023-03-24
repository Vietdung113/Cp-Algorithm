#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
int f, f_min;
bool visited[16];
int cmin = 1e9;
int a[16][16];
int t[16];

void solution(int k) {
    for (int v =1; v <= n; v++) {
        if (!visited[v]) {
            t[k] = v;
            visited[v] = 1;
            f += a[t[k-1]][v];
            if (k == n) {
                if (f_min > f + a[v][0]) f_min = f + a[v][0];
            }else {
                if (f + cmin * (n + 1 - k) < f_min) solution(k+1);
            }
            f -= a[t[k-1]][v];
            visited[v] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f = 0;
    f_min = 1e9;
    memset(t, 0, sizeof t);
    memset(visited, 0, sizeof visited);

    cin >> n;
    for (int i=0; i<=n; i++) {
        for(int j =0; j<=n; j++) {
            cin >> a[i][j];
            if (i != j && a[i][j] < cmin) cmin = a[i][j];
        }
    }
    solution(1);
    for (int i =0; i<= n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
    cout << f_min << endl;
    
}