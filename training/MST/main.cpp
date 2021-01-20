#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 100005
int n,m;
int p[N];
int r[N];
struct Edge{
    int u, v, w;
    bool operator< (Edge & other){
        return w < other.w;
    }
};
vector<Edge> edges;
int find_set(int v){
    if(v==p[v]){
        return v;
    }
    p[v] = find_set(p[v]);
    return p[v];
}
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(r[a] > r[b]){
        p[b] =a ;
    }else
    {
        p[a] =b;
        if(r[a]==r[b]){
            r[a]++;
        }
    }
    
}

int main(){
    cin  >> n >>m;
    for(int i =0;i <m ;i++){
        int u,v,w;
        cin >> u >> v >>w;
        edges.push_back({u,v,w});
        // cout << u << " " <<  v << " " << w << endl;
    }
    sort(edges.begin(), edges.end());
    for(int i =1; i <=n; i++){
        p[i] = i;
        r[i] = 0;
    }
    long long cost = 0;
    for(Edge e: edges){
        // cout << e.u <<" " << e.v <<" " <<  e.w <<endl;
        // cout << "find_set(e.u)= " << find_set(e.u) << "  find_set(e.v)= "<<find_set(e.v) << endl;
        if(find_set(e.u) != find_set(e.v)){
            cost += e.w;
            union_set(e.u,e.v);
            // cout << "add: u->v: " <<  e.u <<" " << e.v <<endl;
        }
    }
    cout << cost;
}