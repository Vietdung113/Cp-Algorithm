#include<bits/stdc++.h>
using namespace std;
#define N 100005
using pil = pair<int,long long>;

int n,u,v;
long long w;
vector<pil> G[N];
long long ans[N];
long long mx1[N];
int b1[N];
long long mx2[N];
int b2[N];
long long res =0;
long long f;
int dfs1(int v, int p){
    for(pil u : G[v]){
        if (u.first != p ){
            long long f = dfs1(u.first,v) + u.second;
            if(f > mx2[v]){
                mx2[v] = f;
                b2[v] = u.first;
            }
            if(mx2[v] > mx1[v]){
                swap(mx2[v], mx1[v]);
                swap(b2[v], b1[v]);
            }
        }
    }
    return mx1[v];
}
void dfs2(int v, int p){
    for(pil u : G[v]){
        if(u.first != p){
            if(b1[v] != u.first){
                f =  mx1[v] + u.second;
                if(f > mx2[u.first]){
                    mx2[u.first] = f;
                    b2[u.first] = v;
                }
                if(mx2[u.first] > mx1[u.first]){
                    swap(mx1[u.first], mx2[u.first]);
                    swap(b2[u.first], b1[u.first]);
                }
            }else
            {
                f =  mx2[v] + u.second;
                if(f > mx2[u.first]){
                    mx2[u.first] = f;
                    b2[u.first] = v;
                }
                if(mx2[u.first] > mx1[u.first]){
                    swap(mx1[u.first], mx2[u.first]);
                    swap(b2[u.first], b1[u.first]);
                }
            }
            dfs2(u.first, v);
        }
    }
}
int main(){
    cin >>n;
    for(int i=0;i<n-1;i++){
        cin >> u >> v >>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs1(1,1);
    dfs2(1,1);
    long long res =0;
    for(int i =1; i<=n; i++){
        res  = max(mx1[i] + mx2[i],res);
    }
    for(int i =1; i<=n; i++){
        cout <<res << endl;
    }



    // for(int i =1 ; i <=n ;i++){
    //     cout << ans[i] << endl;
    // }

}
