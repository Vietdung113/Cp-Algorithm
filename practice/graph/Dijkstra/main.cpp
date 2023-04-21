//https://codeforces.com/problemset/problem/20/C

#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

const int N  = 1e5 + 5;
const int M = 1e5 + 5;
const long long INF = 2000000000000000000LL;
long long D[N];
int trace[N];
int visited[N];
struct edge{ 
    int v;
    long long w;
};
struct node {
    int u;
    long long w;
};
struct cmp{
    bool operator() (node a, node b) {
        return a.w > b.w;
    }
};

vector<edge> G[N];
int main() {
    int n, m;
    int u, v;
    long long w;
    cin >> n >> m;
    for(int i = 0; i<m;i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(trace, -1, sizeof trace);
    memset(visited, 0, sizeof visited);
    for(int i = 0; i<N;i++){
        D[i] = INF;
    }

    priority_queue<node, vector<node>, cmp> pq;
    D[1] = 0;
    pq.push({1, D[1]});

    while(!pq.empty()) {
        node top = pq.top();
        pq.pop();
        int u = top.u;
        if(visited[u]) continue;
        visited[u] = true;
        for(auto e: G[u]) {
            int v = e.v;
            long long w = e.w;
            if(D[v] > D[u] + w){
                D[v] = D[u] + w;
                trace[v] = u;
                pq.push({v, D[v]});
            }
        }
    }
    if(trace[n] == -1){
        cout << "-1\n";
    }
    else{
        vector<int> path;
        while(n!=-1){
            // cout << n << " " ;
            path.push_back(n);
            n = trace[n];
        }
        // cout << endl;
        reverse(path.begin(), path.end());
        for(auto x: path) {
            cout << x << " ";
        }
        cout << endl;

    }

}