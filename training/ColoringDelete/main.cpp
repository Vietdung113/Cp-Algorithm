#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n;
vector<int> G[N];
string s;
int main(){
    cin >> n;
    cin >> s;
    cout << s << endl;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        
    }

}
