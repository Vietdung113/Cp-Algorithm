#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int x[100];
bool visited[100] = {false};
int pred[100][100];
int anws = 0;
struct Node{
    int v;
    int k;
    Node(int _v, int _k){ v = _v; k = _k;};
};
void solution(){
    anws++;
}

bool check(int v, int k){
    if(visited[v]) return false;
    for(int i =1;i<=k-1; i++){
        if (pred[v][x[i]]) return false;
    }
    return true;
}
void solve(){
    cout << "vao solve" << " n= "<< n<< endl;
    stack<Node> S;
    for(int v=n; v>=1; v--){
        S.push(Node(v,1));
    }
    while(!S.empty()){
        Node e = S.top();
        int v= e.v;
        int k = e.k;
        cout << "v= " << v << " k= " << k <<endl;
        if(!check(v,k)){
            bool firstPop = true;
            do
            {
                e = S.top(); v= e.v; k =e.k;
                S.pop();
                cout << "v= " << v << " k= " <<k <<endl;
                if (firstPop) firstPop = false;
                else visited[v] = false;
                
            } while (!S.empty() && S.top().k == k-1);
            continue;
        }
        x[k] = v;
        visited[v] = true;
        if (k==n){
            cout << "Co vao day k?" << endl;
            solution();
            do
            {
                e = S.top(); v= e.v; k = e.k;
                visited[v] = false;
                S.pop();
            } while (!S.empty() && S.top().k == k-1);
        }else
        {
            for(int u=n;u>=1;u--) {
                if(check(u,k+1)) S.push(Node(u,k+1));
            }
        }
    }
    cout << anws;
   
}
void input(){
    cin >> n >> m;
    cout << "n= " << n << " m=" <<m <<endl;
    for(int i=1; i<=n;i++){
        for(int j =1; j<=n;j++){
            pred[i][j] = 0;
        }
    }
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        pred[u][v] = 1;
    }
}

int main(){
    input();
    cout << "qua input" <<endl;
    cout << "n= " << n << " m=" << m <<endl;

    solve();
    return 0;
}