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
int load=0;
int max_people;
void solution() {
    f_min = min(f_min , f + c[x[2*n]][x[0]]);
    // if (f + c[x[2*n]][x[0]] < f_min) f_min = f + c[x[2*n]][x[0]];
}

bool check(int v, int k) {
    //return !visited[v]&&v>k&&people[v] <=max_people;
    if (visited[v]) return false;
    if(v>n && visited[v-n]==false) return false;
    if(v<=n && load >= max_people) return false;
    return true;
}

void Try(int k) {
    // optimize to fine f_min faster
    
    for (int v = 1; v <= 2*n; v++) {
        if (check(v, k)) {
            x[k] = v;
            visited[v] = true;
            f = f + c[x[k - 1]][x[k]];
            if(v<=n) load++;
            else load--;
            //people[k] = people[x[k-1]] + 1; 
            if (k == 2*n) solution();
            else {
                if (f + (2*n + 1 - k) * cmin < f_min) Try(k + 1);
            }
            visited[v] = false;
            f = f - c[x[k - 1]][x[k]];
            if(v<=n) load--;
            else load++;
        }
    }
}

void solve() {
    for (int v = 1; v <= 2*n; v++) visited[v] = false;
    x[0] = 0;
    f = 0; f_min = 1e9;
    Try(1);
    cout << f_min << endl;
}

void input() {
    cin >> n >> max_people;
    cmin = 1e9;
    for (int i = 0; i <= 2*n; i++)
        for (int j = 0; j <= 2*n; j++)
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