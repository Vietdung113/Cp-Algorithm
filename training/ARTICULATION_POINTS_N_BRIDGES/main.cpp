#include<bits/stdc++.h>
using namespace std;

#define N 100005
#define M 100005

bool visited[N];
vector<int> G[N];
int num[N];
int low[N];
int n, m;
int t=0;
int n_articulation = 0;
int n_bridge = 0;
int root;
int children;
int arti[N];
void dfs(int v,int p){
    visited[v] = true;
    t++;
    num[v] = t;
    low[v] = t;
    // int children = 0;
    for(int u: G[v]){
        // if(u==p) continue; 
        if(!visited[u]){
            if(v==root) children++;
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] >= num[v]){
                arti[v] = true;
            }
            if(low[u] > num[v]){
                n_bridge+=1;
            }
        }else
        {
            if(u!=p) low[v] = min(low[v], num[u]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i =0; i <m ;i ++){
        int x ,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i =1 ;i <=n;i++){
        if(!visited[i]) {
            root= i;
            t = 0;
            children = 0;
            dfs(i,-1);
            if(children <=1 ) arti[root] = false;
        }
    }
    for(int i =1; i<=n ;i++){
        if(arti[i]) n_articulation+=1;
    }
    cout << n_articulation << " " << n_bridge << endl;
}