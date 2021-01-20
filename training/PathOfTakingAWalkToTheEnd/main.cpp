#include<bits/stdc++.h>
using namespace std;
#define N 100005
int Testcase;
vector<pair<int,int>>  G[N];

int n,m;
int u,v ;
unsigned long long w;
unsigned long long W[N];
unsigned long long f[N];
using puli = pair<unsigned long long,int>;
using piul = pair<int, unsigned long long>;

unsigned long long st[N];
int idx[N];

bool comp(int a, int b){
    // cout <<" st[" << a <<"]= " << st[a] << " st[" << b << "]= " << st[b] << endl;
    return st[a] < st[b];
}
void cal_shortest_path(){
    memset(W, 255, sizeof W);
    // cout << W[0]<<endl;
    priority_queue<puli, vector<puli>, greater<puli>> q;
    W[1] = 0;
    q.push({W[1],1});
    while (!q.empty())
    {
        int w = q.top().first;
        int v = q.top().second;
        q.pop();
        for(piul u: G[v]){
            int weight_next_to_v = u.second;
            int next_v = u.first;
            if(W[v] + weight_next_to_v < W[next_v]){
                W[next_v] = W[v] + weight_next_to_v;
                q.push({W[next_v], next_v});
            }
        }
    }
    memset(st,0, sizeof st);
    memset(idx, 0, sizeof idx);
    for(int i =1;i <=n;i++){
        st[i] = W[i];
        idx[i] = i;
        // cout << W[i] << " ";
        // cout << "W[i]= " << W[i] << " ";
        // cout <<"idx= " << i << " " << endl;
    }
    // cout << endl;
    sort(idx+1, idx+n+1, comp);
    // for(int i=1;i<=n; i++){
    //     cout << idx[i] << " " << st[idx[i]] << endl;
    // }
    // cout << endl;
}
bool check(int v){
    for(piul u: G[v]){
        int weight_next_to_v = u.second;
        int next_v = u.first;
        if(st[v] + weight_next_to_v == st[next_v]){
            return false;
        }
    }
    return true;
}
long long count_path(){
    // for(pii )
    memset(f, 0, sizeof f);
    long long ans = 0;
    f[1] = 1;
    for(int i=1;i<=n;i++){
        int v = idx[i];
        for(piul s: G[v]){
            unsigned long long weight_next_to_v = s.second;
            int next_v = s.first;
            if(st[v] + weight_next_to_v == st[next_v]){
                f[next_v] += f[v];
                if(f[next_v] >= 1000000007){
                    f[next_v] -= 1000000007;
                }
            }
        }
        if (check(v)){
            ans+=f[v];
            if(ans>= 1000000007){

                ans -=1000000007;
            }
        }
    }
    // cout << ans;
    return ans;
    // int ans = 0;
    // for(int i=1;i<=n;i++){
    //     ans += f[v];
    // }
}

int main(){
    cin >> Testcase;
    for(int T=1; T<=Testcase; T++){
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        for(int i =0;i<m;i++){
            cin >> u >> v >> w;
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));
        }
        cal_shortest_path();
        long long ans = count_path();
        cout << "#" << T << " " << ans << endl;


        // break;
    }
}