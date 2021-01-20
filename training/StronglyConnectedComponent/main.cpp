#include<bits/stdc++.h>
using namespace std;

#define N 100005
#define M 1000006
int n, m;
vector<int> G[N];
int visited[N] = {false};
vector<int> G_[N];
int visited_[N] = {false};

int f[N];
pair<int, int> tmp[N];
int timer=0;
void dfs_g(int v){
    // timer++;
    visited[v] = true;
    for(int i=0; i< G[v].size(); i++){
        if(!visited[G[v][i]]) dfs_g(G[v][i]);
    }
    timer++;
    f[v] = timer;
}
void dfs_g_stack(int v){
    vector<int> stu;
    vector<int> sti;
    stu.push_back(v);
    sti.push_back(0);
    visited[v] = true;
    while(!stu.empty()){
        int v = stu.back();
        int &i = sti.back();
        if(i < G[v].size()){
            int u = G[v][i++];
            if(!visited[u]){
                stu.push_back(u);
                sti.push_back(0);
                visited[u] = true;
            }
        }else
        {
            timer++;
            f[v] = timer;
            stu.pop_back();
            sti.pop_back();
        }
    }
}
void dfs_g_(int v){
    visited_[v] = true;
    for(int i=0; i < G_[v].size();i++){
        if(!visited_[G_[v][i]]) dfs_g_(G_[v][i]);
    }
}
void dfs_g_stack_(int v){
    vector<int> stu;
    vector<int> sti;
    stu.push_back(v);
    sti.push_back(0);
    visited_[v] = true;
    while (!stu.empty())
    {
        int c = stu.back();
        int &i = sti.back();
        if(i < G_[c].size()){
            int k = G_[c][i++];
            if(!visited_[k]){
                stu.push_back(k);
                sti.push_back(0);
            }
        }
        else
        {
            stu.pop_back();
            sti.pop_back();
        }
        
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    int u , v;
    for(int i =0; i < m ;i ++){
        cin >> u >> v;
        G[u].push_back(v);
        G_[v].push_back(u);
    }
    for(int i=1; i <=n; i++){
        if(!visited[i]){
            dfs_g_stack(i);
            // dfs_g(i);
        }
    }
    for(int i=1;i<=n; i++){
        tmp[i] = make_pair(f[i],i);
    }
    sort(tmp+1,tmp+n+1);
    // for(int i=1;i<=n; i++){
    //     cout << tmp[i].first << " " << tmp[i].second << endl;
    // }
    int ans = 0;
    for(int i = n ; i >=1; i--){
        if(!visited_[tmp[i].second]){
            // dfs_g_(tmp[i].second);
            dfs_g_(tmp[i].second);
            ans += 1;
        }
    }
    cout << ans;
    // cout << endl;

}