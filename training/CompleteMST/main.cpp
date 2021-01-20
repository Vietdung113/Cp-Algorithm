#include<bits/stdc++.h>
using namespace std;
#define N 100005

int n,m;
int u,v;
long long w;
struct Edge{
    int u, v;
    long long w;
    bool operator< (Edge & other){
        return w < other.w;
    }
};
using pii = pair<int,int>;
int p[N];
vector<Edge> E;
vector<Edge> E_;
vector<pii> G[N];
int d[N];
void make_set(int v){
    p[v] = v;
    d[v] = 0;

}
int find_set(int v){
    if(v==p[v]){
        return v;
    }
    return p[v] = find_set(p[v]);
}
void union_set(int a, int b){
    a= find_set(a);
    b = find_set(b);
    if(a!=b){
        p[a] = b;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >>m;
    for(int i =0; i <m ;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        E.push_back({u,v,w});
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> u >> v;
        for(pii s: G[u]){
            if(s.first == v){
                E_.push_back({u,v,s.second});
            }
        }
    }
    for(int i=1; i <=n;i++)
    {
        make_set(i);
    }
    sort(E_.begin(), E_.end());
    long long cost = 0;
    int cnt = 0;
    for(Edge e: E_){
        if(find_set(e.u)!=find_set(e.v)){
            cost += e.w;
            // cout <<"join: " << e.u << " " << e.v << " cost: " << cost << endl;
            cnt +=1;
            union_set(e.u,e.v);
        }
    }
    // cout << endl;
    long long ans = 1e10;
    // cout << ans << endl;
    int check = false;
    for(Edge e: E){
        if(find_set(e.u)!=find_set(e.v)){
            ans = min(ans, cost+e.w);
            // cout <<"join: " << e.u << " " << e.v << " cost: " << cost + e.w << endl;
            check = true;
        }
    }
    if(check && cnt == n-2)
        cout << ans;
    else
    {
        cout << "-1";
    }
}