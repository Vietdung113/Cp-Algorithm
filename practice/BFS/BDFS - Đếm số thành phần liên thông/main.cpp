// http://lequydon.ntucoder.net/Problem/Details/4601
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];

vector<int> G[N];
int component;

void bfs(int v) {
    component += 1;
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        v = q.front();
        q.pop();
        for(auto u: G[v]) {
            if(!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    memset(visited, sizeof visited, false);
    component = 0;
    int n, m;
    cin >> n >> m;
    int u,v;
    for(int i=1;i<=m;i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        if (!visited[i]) bfs(i);
    }
    cout << component;

}