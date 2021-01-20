#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 100005
vector<int> G[N];
int visited[N];
int d[N];
int n, m ;
bool solve(){
    // for(int i =1;i<=n;i++){
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    memset(visited, -1 , sizeof visited);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u: G[v]){
            if(visited[u]==-1){
                visited[u] = 1 - visited[v];
                q.push(u);
            }else
            {
                if(visited[u] == visited[v]){
                    return false;
                }
            }
        }
    }

    // }
   
   return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    int u,v;
    cin.tie(NULL);
    cin >> n >> m;
    for(int i =0;i<m;i++){
        cin  >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool ans = solve();
    cout << ans;
}