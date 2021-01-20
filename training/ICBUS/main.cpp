#include<bits/stdc++.h>
using namespace std;
#define N 10002
int W[N];
int D[N];
int n, k, w, d;
int x,y;
bool visited[N];
struct Node{
    int v, d, w;
};
struct Node_{
    int v, w;
};
vector<int> G[N];
vector<pair<int,int>> G_[N];
void convertGraph(){
    for(int i=1;i<=n;i++){
        // if(i!=5) continue;
        memset(visited,0, sizeof visited);
        queue<Node> q;
        q.push({i,D[i],0});
        // cout << "D[i]= " << D[i]  << endl;
        visited[i] = true;
        while (!q.empty())
        {
            Node k = q.front();
            // cout << k.d << endl;
            q.pop();
            if(k.d > 0){
                for(int u: G[k.v]){
                    if(!visited[u]){
                        // cout << u << " " << W[k.v] << " " << k.v;
                        visited[u] = true;
                        q.push({u, k.d-1, W[i]});
                        G_[i].push_back(make_pair(u, W[i]));
 
                    }
               }
            //    cout << endl;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << "start vertex: " << i << endl;
    //     for(pair<int,int> s: G_[i]){
    //         cout << s.first << " " << s.second << endl;
    //     }
    //     cout << endl;
    // }

}
int minW[N];
void bfs(){
    memset(minW, 10005, sizeof minW);
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,1});
    minW[1] = 0;
    while (!q.empty())
    {
        int d_v = q.top().first;
        int v = q.top().second;
        q.pop();
        for(pair<int,int> s: G_[v]){
            int weight_next_to_v = s.second;
            int next_v = s.first;
            if(minW[v] + weight_next_to_v < minW[next_v]){
                minW[next_v] = minW[v] + weight_next_to_v;
                q.push({minW[next_v], next_v});
            }
        }
    }

    cout << minW[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> w >> d;
        W[i] = w;
        D[i] = d;
    }
    for(int i =1;i <=k;i++ ){
        cin >> x >>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    convertGraph();
    bfs();
}