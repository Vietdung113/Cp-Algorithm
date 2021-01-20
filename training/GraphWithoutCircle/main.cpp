#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 200005
vector<int> G[N];
int TestCase;
int n,m,k;
int u,v,d;
int r[N];
int main(){
    cin >> TestCase;
    for(int T=1;T<=TestCase; T++){
        cin >> n >> m >> k;
        memset(r,0,sizeof r);
        for(int i =1; i <= n; i++){
            G[i].clear();
        }
        for(int i = 1; i<=m; i++){
            cin >> u >> v >> d;
            if(d==1){
                G[u].push_back(v);
                r[v]+=1;
                // cout << r[v] << " ";
            }
        }
        // cout << endl;
        priority_queue<int, vector<int>,greater<int>> q;
        vector<int> topo;
        for(int i = 1; i <=n ;i++){
            if(r[i]==0) q.push(i);
        }
        while (!q.empty())
        {
            // cout << q.top() << " ";
            int v = q.top();
            // cout << v << " ";
            topo.push_back(v);
            q.pop();
            for(int u: G[v]){
                r[u]-=1;
                if(r[u]==0){
                    q.push(u);
                }
            }
        }
        if(topo.size() < n) cout << "#" << T << " -1"<<endl;
        else
        {
            cout << "#" << T << " " << topo[k-1] << endl;
        }
        
        // break;
    }
}