#include<bits/stdc++.h>
using namespace std;
#define N 21
#define M 26
struct Edges{
    int u,v;
};
Edges E[M];
Edges x[M];
int n,m;
int u,v;
bool visited[M];
int ans;
int p[N];

int find_set(int v){
    if(v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        p[a] =b;
    }
}
bool check(Edges x[]){
    int c = 0;
    for(int i=1;i <=n ;i++){
        p[i] = i;
    }
    for(int i =1; i<=n-1 ;i++){
        if(find_set(x[i].u)!= find_set(x[i].v)){
            c++;
            union_set(x[i].u, x[i].v);
        }
        // cout << x[i].u << " " << x[i].v << endl;
    }   

    // cout <<endl;
    if(c!=n-1) return false;
    return true;
    
}

void Try(int k, int idx){
    for(int i=idx; i<= m; i++){
        if(!visited[i]){
            x[k] = E[i];
            visited[i] = true;
            if(k == n-1){
                if(check(x)) ans++;
            }else
            {   
                Try(k+1, i+1);
            }
            visited[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i =1;i<=m;i++){
        cin >> u >> v;
        E[i] = {u,v};
    }

    Try(1,1);
    cout << ans;
}