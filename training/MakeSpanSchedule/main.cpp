#include<bits/stdc++.h>
using namespace std;
#define N 10004
#define M 200005

// using pii = pair<int,int>;
int d[N];
vector<int> G[N];
int r[N];
int n,m;
int ans=0;
struct State{
    int v, e;
};
vector<State> L;
void solve(){
    queue<State> q;
    for(int i =1;i <=n;i++)  {
        if(r[i] == 0){
            q.push({i,d[i]});
        }
    }
    while (!q.empty())
    {
        State v = q.front();
        ans = max(ans, v.e);
        q.pop();
        for(int u: G[v.v]){
            r[u] -= 1;
            if(r[u]==0){
                q.push({u, v.e + d[u]});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i =1; i<=n;i++){
        cin >> d[i];
    }

    for(int i=1;i<=m; i++){
        int u,v;
        cin >> u >>v ;
        G[u].push_back(v);
        r[v] +=1;
    }
    // for(int i=1;i<=n;i++){
    //     cout << "vertex i : " << i << ": ";
    //     for(int u : G[i]){
    //         cout << u << " ";
    //     }
    //     cout << endl;
    // }
    solve();
    cout << ans;
}