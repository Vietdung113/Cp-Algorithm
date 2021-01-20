#include<bits/stdc++.h>
using namespace std;

#define N 100005
#define M 100005
vector<int> v[N];
bool visited[N] = {false};
int n,m;
void dfs(int u){
    visited[u] = true;
    // for(int u: v[i]){
    //     if(!visited[u]) dfs(u);
    // }
    for(int i =0 ; i < v[u].size(); i++){
        if(!visited[v[u][i]]) dfs(v[u][i]);
    }
}
void dfs_stack(int u){
    vector<int> stu;// dinh
    vector<int> sti; // vong lap
    stu.push_back(u);
    sti.push_back(0);
    visited[u] = true;
    while (!stu.empty())
    {
        // cout << "vao day chua nhi" << endl;
        int c = stu.back();
        int &i = sti.back();
        // cout << v[c].size() << endl;
        if( i < v[c].size()){
            // cout << i << endl;
            int k = v[c][i++];
            if(!visited[k]){
                stu.push_back(k);
                sti.push_back(0);
                visited[k] = true;
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
    cin >> n >>m;
    for(int i =0 ; i <m ; i++){
        int x, y;
        cin >> x >>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans =0;
    for(int i=1; i <=n ;i++){
        // for(int i =1 ;i<=n; i++){
        //     // cout << visited[i] << " ";
        // }

        // cout << endl;

        if(!visited[i]){
            ans+=1;
            dfs_stack(i);
        }
    }
    cout << ans;
    // for(int i =1; i <=n ;i++){
        // cout << "vertex " << i << " : ";
        // for(int j =0 ; j < v[i].size(); j++){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
    // }
}