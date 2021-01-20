#include<bits/stdc++.h>
using namespace std;

#define N 1000005
int Testcase;
int n, r;
int ans = 0;

vector<int> c[1000005];
int T[1000005];

void add(int u, int val){
    for(;u<=n;  u+= u &(-u)){
        T[u] += val;
    }
}
int get(int u){
    int w= 0;
    for(;u; u -=u &(-u)){
        w+=T[u];
    }
    return w;
}
void dfs(int u){
     // c[u] cac con cua u
    add(u, 1);
    ans +=  get(n) - get(u);
    // cout << "u : " << u  << "     " << get(n) - get(u) << endl;
    for(int i =0; i < c[u].size(); i++){
        dfs(c[u][i]);
    }
    add(u,-1);
}
void dfs_stack(int u){
    vector<int> stu;
    vector<int> sti;
    stu.push_back(u);
    sti.push_back(0);

    add(u,1);
    while(!stu.empty()){
        u = stu.back();
        int &i = sti.back();
        if(i < c[u].size()){
            int v = c[u][i++];
            stu.push_back(v);
            sti.push_back(0);
            add(v,1);
            ans += get(n) - get(v);
        }
        else
        {
            add(u,-1);
            stu.pop_back();
            sti.pop_back();
        }
    }
}
int main(){
    cin >> Testcase;
    int a,b;
    for(int t=1; t<=Testcase ; t++){

        cin >> n >> r;
        for(int i =1;i <=n;i++){
            c[i].clear();
        }
        for(int i =1; i <n; i++){
            cin >> a >> b;
            c[a].push_back(b);
        }
       ans = 0;
        // dfs(r);
        dfs_stack(r);
        cout << ans<<endl;
    }
}