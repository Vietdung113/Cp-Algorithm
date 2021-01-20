#include <bits/stdc++.h>

using namespace std;

int N,T,D;
int a[1001], t[1001];
int S[1001][101];
bool dd[1001][101];

int calc(int i, int remain){
    if (S[i][remain]) return S[i][remain];
    // dd[i][remain] = true;
    for(int j=max(i-D,0); j<i;j++){
        if(t[i]<=remain)
            S[i][remain] = max(S[i][remain],calc(j,remain-t[i])+a[i]);
    }
    return S[i][remain];
}
int main() {
    cin >> N >> T >>D;
    for(int i=1;i<=N;i++) cin >> a[i];
    for(int i=1;i<=N;i++) cin >> t[i];
    int anws = 0;
    memset(dd, false, sizeof dd);
    memset(S,0,sizeof S);
    for(int i=1;i<=N;i++){
        anws = max(anws,calc(i,T));
    }
    cout << anws;
}