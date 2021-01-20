#include<bits/stdc++.h>
using namespace std;
#define N 10005
int n,m;
int u,v;
vector<int> G[N];
bool visited[N];
vector<int> ans;
int start ;
bool res;
bool check(int v){
    // cout << ans.size() << endl;
    // if(ans.size()==n) cout << 
    // start = 1;"vao day roi chu" << endl;
    if(ans.size() !=n ) return false;
    for(int k : G[v]){
        if(k==start) return true;
    }
    return false;
}
void dfs(int v){
    ans.push_back(v);
    if(check(v)) {
        res = true;
    }
    visited[v] = true;
    for(int u: G[v]){
        if(!visited[u]) dfs(u);
    }
    visited[v] = false;
    ans.pop_back();
}
void dfs_stack(int v){
    vector<int> stu;
    vector<int> sti;
    ans.push_back(v);
    stu.push_back(v);
    sti.push_back(0);
    if(check(v)){
        res = true;
    }
    visited[v] = true;
    while (!stu.empty())
    {
        int v = stu.back();
        int &i = sti.back();
        // cout << G[v].size() << " " << i << endl;
        if(i < G[v].size()){
            int u = G[v][i++];
            if(!visited[u]){
                stu.push_back(u);
                sti.push_back(0);
                visited[u] = true;
                ans.push_back(u);
                if(check(u)){
                    res = true;
                }
            }
        }
        else
        {
            visited[v] = false;
            ans.pop_back();
            stu.pop_back();
            sti.pop_back();
        }
        
    }
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // cout << "vao day roi" << endl;
    start = 1;
    dfs_stack(1);
    cout <<res << endl;
 }