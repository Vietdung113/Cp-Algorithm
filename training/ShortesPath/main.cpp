#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 100005
int n, m, s, t;

vector<pair<int,int>> adj[N];
int d[N];

int shortestPath(){
    memset(d,int(1e6+5), sizeof d);
    // cout << s << endl;
    d[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({d[s],s});
    while (!q.empty())
    {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        // if(d[v]!=d_v) continue;
        for(int i=0; i < adj[v].size(); i++){
            int distance_next_to_v = adj[v][i].second;
            int next_v = adj[v][i].first;
            // cout << "d[v]= " << d[v] << " d[next_v]= " << d[next_v] << endl;
            if(d[v]+ distance_next_to_v < d[next_v]){
                // cout << "v " << v << " to " << next_v <<endl;
                d[next_v] = d[v] + distance_next_to_v;
                // cout << "d[next_v] = " << d[next_v] << endl;
                // if(next_v == t){
                //     return d[next_v];
                // }
                q.push({d[next_v], next_v});
            }
        }
    }
    if(d[t] != int(1e6+5)){
        return d[t];
    }
    return -1;

}
int main(){
    cin >> n >> m; 
    for(int i=0;i<m;i++){
        int u, v,w;
        cin >> u >> v >>w;
        adj[u].push_back(make_pair(v,w));
    }
    cin >> s >> t;
    // cout << s << " " << t << endl;
    int ans = shortestPath();
    cout << ans;
    // for(int i =1; i <=n ;i++){
    //     cout << "vertex: " << i << " can go to: ";
    //     for(pair<int,int> q: adj[i]){
    //         cout << q.first << " ";
    //     }
    //     cout << endl;
    // }

}