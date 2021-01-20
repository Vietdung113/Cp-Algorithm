/// https://cp-algorithms.com/graph/edmonds_karp.html 
#include<bits/stdc++.h>
using namespace std;
#define N 1005
using pii = pair<int,int>;
vector<int> G[N];
int C[N][N];
int n,m;
int s,e;
int u,v,w;
int bfs(int s, int e, vector<int>& p){
    fill(p.begin(),p.end(), -1);
    p[s] = -2;
    queue<pii> q;
    q.push({s,1e4});
    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int next: G[cur]){
            // cout << next << " " << p[next] << " " << C[cur][next] << endl;
            if((p[next]==-1) && (C[cur][next]!=0)){
                // cout << C[cur][next] << " " << p[next] << endl;
                p[next] = cur;
                int new_flow = min(flow,C[cur][next]);
                // cout << new_flow<< endl;
                if(next == e){
                    // cout << new_flow << endl;
                    return new_flow;
                }
                // cout << next << " " << new_flow << endl;
                q.push({next,new_flow});
            }
        }
    }
    return -1;
}
int max_flow(int s, int e){
    int flow = 0; 
    // cout << n << endl;
    vector<int> p(n+1);
    int new_flow = bfs(s,e,p);
    // cout << "new flow: " << new_flow << endl;
    while (new_flow!=-1)
    {   
        // cout << new_flow << endl;
        flow += new_flow;
        int cur = e ;
        while (cur!=s)
        {
            int prev = p[cur];
            C[prev][cur] -= new_flow;
            C[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(s,e,p);
    }

    return flow;
}
int main(){
    cin >> n >> m;
    // cout << n << " " << m << endl;
    cin >> s >> e;
    memset(C, 0, sizeof C);
    for(int i =0;i<m;i++){
        cin >> u >> v >> w;
        G[u].push_back(v);
        C[u][v] = w;
    }
    // for(int i =1; i <=n ;i++){
    //     cout << i << ": ";
    //     for(int u : G[i]){
    //         cout << u  << " W: " << C[i][u] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = max_flow(s,e);
    cout << ans << endl;
}