#include<bits/stdc++.h>
using namespace std;
#define N 10005

int d[N];
int n,m;
int u,v;
vector<int> G[N];
int main(){
    cin >> n >>m;
    for(int i =0;i <m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        d[v]+=1;
    }
    queue<int> q;
    for(int i =1; i<=n ;i++){
        if(d[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int u: G[v]){
            d[u] -= 1;
            if(d[u]==0){
                q.push(u);
            }
        }
    }
    
}