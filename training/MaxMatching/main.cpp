/// https://codeforces.com/group/kBYGBfIPWt/contest/311972/problem/T
/// hint: Maxium flow  https://cp-algorithms.com/graph/edmonds_karp.html
#include<bits/stdc++.h>
using namespace std;

#define N 10003
#define M 10003
using pii = pair<int,bool>;
vector<int> G[N + M +2];
bool C[N+M+2][N+M+2];
int n,m,k,t;
int bfs(int s, int e, vector<int>& p){
    fill(p.begin(),p.end(), -1);
    p[s] = -2;
    queue<pii> q;
    q.push({s,1});
    while (!q.empty())
    {
        int cur = q.front().first;
        bool flow = q.front().second;
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
    vector<int> p(n+m+3);
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
    cin  >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> t;
            C[i][t+n] = 1;
            G[i].push_back(t+n);
        }
    }
    int s = 0;
    int e =n+m+1;
    for(int i=1;i<=n;i++){
        C[s][i] = 1;
        G[s].push_back(i);
    }
    for(int i=1;i<=m;i++){
        C[n+i][e] = 1;
        G[n+i].push_back(e);
    }
    // for(int i=0; i<= n+m+1;i++){

    // }
    int ans = max_flow(s,e);
    // int ans=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=n+1;j <= n+m; j++){
    //         ans+=C[i][j];
    //     }
    // }
    cout << ans;
    // for(int i=0;i<=n+m+1 ; i++){
    //     cout << "vertex : " << i << ": ";
    //     for(int u: G[i]){
    //         cout << u << " ";
    //     }
    //     cout << endl;
    // }

}
