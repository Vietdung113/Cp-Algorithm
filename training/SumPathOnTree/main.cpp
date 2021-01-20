#include<bits/stdc++.h>
using namespace std;

#define N 1000005
using pil = pair<int,long long>;
vector<pil> G[N];
int n,u,v;
long long w;
int cnt[N];
long long S[N];
long long f[N];
void dfs1(int v,int p){
    cnt[v] = 1;
    S[v] = 0;
    for(pil u : G[v]){
        if(u.first != p){
            dfs1(u.first,v);
            cnt[v] += cnt[u.first];
            S[v] += S[u.first] + u.second * cnt[u.first];
        }
    }
}
void dfs2(int v, int p){
    for(pil u: G[v]){
        if(u.first != p){
            f[u.first]  = f[v]  + u.second * (n - 2 * cnt[u.first]);
            dfs2(u.first, v);
        }
    }
}
int main(){
    cin >> n;
    for(int i =1;i <=n-1;i++){
        cin >> u >> v >> w;
        // cout << u << " " << v <<endl;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    // for(int i =1; i<=n ; i++){
    //     cout << "vertex: " << i  << ": ";
    //     for(pil u : G[i]){
    //         cout << u.first << " ";
    //     }
    //     cout << endl;
    // }
    dfs1(1,1);
    f[1] = S[1];
    dfs2(1,1);
    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,f[i]);
    }
    cout << ans;
}