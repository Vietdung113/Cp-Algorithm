#include <bits/stdc++.h>
#include <iostream>
#include<vector>

using namespace std;

/*
Model: x[1, ... , n], x[i] la giao vien phan day mon i

load[t]: so gio phan cho giao vien t
*/

int min_load;
int n,m;
int h[21];
int A[21][21];
int load[21];
vector<int> T[21];
int x[21];
bool check(int v, int k){
    for(int i = 1; i<= k-1; i++){
        if(A[i][k] ==1 && x[i] ==v) return false;
    }
    return true;
}

void solution(){
    int max_load = 0;
    for(int i=1; i<=n; i++) max_load = max(max_load, load[i]);
    min_load = min(min_load, max_load);
}

void TRY(int k){
    for(int i=0; i<T[k].size(); i++){
        int v = T[k][i];
        if(check(v,k)){
            x[k] = v; load[v] += h[k];
            if(k==n) solution();
            else{
                if(load[v] < min_load)
                    TRY(k+1);
            }
            load[v] -= h[k];
        }
    }

}

void solve(){
    min_load = 1e9;
    for(int i=1; i<=m; i++) load[i] = 0;
    TRY(1);
    cout<<min_load<< endl;
}

int main() {
    cin>> n>> m;
    for(int i=1;i<=n;i++) cin>>h[i];
    
    for(int i = 1; i <= n; i++){
        int k; cin>>k;
        for(int j=0;j < k; j++){
            int t; cin>>t;
            T[i].push_back(t);
        }
    }
    
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) cin>>A[i][j];
    
    solve();
	
}