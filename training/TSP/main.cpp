#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int n;
int c[N][N];
int cmin;
int f, f_min;
int xmin[N];
bool visited[N];
int x[N];
void solution() {
    if (f + c[x[n]][x[0]] < f_min) f_min = f + c[x[n]][x[0]];
}

bool check(int v, int k) {
    return !visited[v];
}

void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            visited[v] = true;
            f = f + c[x[k - 1]][x[k]];
            if (k == n) solution();
            else {
                if (f + (n + 1 - k) * cmin < f_min) Try(k + 1);
            }
            visited[v] = false;
            f = f - c[x[k - 1]][x[k]];
        }
    }
}

void solve() {
    for (int v = 1; v <= n; v++) visited[v] = false;
    x[0] = 0;
    f = 0; f_min = 1e9;
    Try(1);
    cout << f_min << endl;
}

void input() {
    cin >> n;
    cmin = 1e9;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            int val;
            cin >> val;
            c[i][j] = val;
            if (i != j && cmin > c[i][j]) cmin = c[i][j];
        }
}

int main() {
    input();
    solve();
}