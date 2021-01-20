#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n,u,v;
long long w;
using pil = pair<int, long long>;
vector<pil> G[N];
long long S[N];
long long f[N];
int cnt[N];

void dfs1(int v, int p){
    cnt[v] = 1;
    S[v] = 0;
    for(pil u: G[v]){
        if(p != u.first){
            dfs1(u.first,v);
            cnt[v] += cnt[u.first];
            S[v] = S[v] + S[u.first] + u.second * cnt[u.first];
        }
   }
}
void dfs1_stack(int v, int p){
    stack<int> stu;
    stack<int> sti;
    stack<int> stp;
    stu.push(v);
    stp.push(p);
    sti.push(0);
    cnt[v] = 1;
    S[v] = 0;

    while (!stu.empty())
    {
        int v = stu.top();
        int p = stp.top();
        // cout << v << " " << p << endl;
        int &i = sti.top();
        if(i < G[v].size()){
            pil u = G[v][i];
            i+=1;
            if( u.first!=p ){
                stu.push(u.first);
                sti.push(0);
                stp.push(v);
                cnt[u.first] = 1;
                S[u.first] = 0;
            }
        }else
        {
            stu.pop();
            sti.pop();
            stp.pop();
            if(stu.empty()){
                break;
            }
            cnt[stu.top()] += cnt[v];
            S[stu.top()] = S[stu.top()] + S[v] + G[stu.top()][sti.top()-1].second * cnt[v];
        }
    }
}
void dfs2(int v, int p){
    for(pil u : G[v]){
        if(u.first != p){
            // cout << "u: " << u.first  << " cnt[u]: " << cnt[u.first] << " f[u]: " << f[u.first] << " v: " << v << " f[v]: " << f[v] <<endl;
            // cout <<endl;
            f[u.first]  = f[v]  + u.second * (n - 2 * cnt[u.first]);
            dfs2(u.first, v);
            // cout << "u: " << u.first  << " cnt[u]: " << cnt[u.first] << " f[u]: " << f[u.first] << " v: " << v << " f[v]: " << f[v] <<endl;
        }
    }
}
void dfs2_stack(int v, int p){
    vector<int> stu;
    vector<int> sti;
    vector<int> stp;

    stu.push_back(v);
    stp.push_back(p);
    sti.push_back(0);
    while (!stu.empty())
    {
        int v = stu.back();
        int p = stp.back();
        int&i = sti.back();
        if(i< G[v].size()){
            pil u = G[v][i];
            i+=1;
            if(u.first!=p){
                f[u.first]  = f[v]  + u.second * (n - 2 * cnt[u.first]);
                stu.push_back(u.first);
                sti.push_back(0);
                stp.push_back(v);
            }
        }
        else
        {
            stu.pop_back();
            sti.pop_back();
            stp.pop_back();
        }
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n-1;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    // dfs1(1,1);
    dfs1_stack(1,1);
    // for(int i=1;i <=n ;i++){
    //     cout << S[i] << " ";
    // }
    // cout << endl;
    f[1] = S[1];
    // dfs2(1,1);
    dfs2_stack(1,1);
    for(int i=1; i<=n ;i++){
        cout << f[i] << endl;
    }
    // cout << endl;

}