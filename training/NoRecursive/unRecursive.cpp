#include<bits/stdc++.h>
using namespace std;
int n;
int x[100];
struct Node{
    int v;
    int k;
    Node(int _v, int _k){ v = _v; k = _k;};
};
void solution(){
    for(int i =1; i<=n;i++) cout << x[i] << " ";
    cout <<endl;
}
bool check(int v, int k){
    return true;
}
void solve(){
    stack<Node> S;
    for(int v=1; v>=0; v--){
        S.push(Node(v,1));
    }
    while(!S.empty()){
        Node e = S.top();
        int v= e.v;
        int k = e.k;
        if(!check(v,k)){
            do
            {
                e = S.top(); v= e.v; k =e.k;
                S.pop();
            } while (!S.empty() && S.top().k == k-1);
            continue;
        }
        x[k] = v;
        if (k==n){
            solution();
            do
            {
                e = S.top(); v= e.v; k = e.k;
                S.pop();
            } while (!S.empty() && S.top().k == k-1);
            
        }else
        {
            for(int u=1;u>=0;u--) S.push(Node(u,k+1));
        }
        
    }
   
}
int main(){
    n =3;
    solve();
}