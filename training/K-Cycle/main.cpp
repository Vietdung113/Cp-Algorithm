#include<bits/stdc++.h>
using namespace std;
#define N 51

vector<int> G[N];
int n, m , k;
int u,v;
bool visited[N];
int root;
vector<int> res;
int ans = 0 ;
bool check(int v){
    if (res.size() != k ) return false;
    for(int u : G[v]){
        if(u==root) return true;
    }
    return false;
}

void dfs(int v){
    // cout << v << endl;
    res.push_back(v);
    visited[v] = true;
    if(check(v)) 
    {
        ans+=1;
        // for(int p : res){
            // cout << p << " " ;
        // }
        // cout << endl;
        // return;
    }
    for(int u: G[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
    visited[v] = false;
    res.pop_back();
}
void solve(){
    for(int i =1;i <=n;i++){
        memset(visited,0, sizeof visited);
        root = i;
        res.clear();
        dfs(i);
        // break;
    }
}
int main(){
    cin >> n >> m >> k;
    // cout << n << " " << m << " "  << k << endl;
    for(int i =0;i<m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    solve();
    cout << ans / (2*k);
}