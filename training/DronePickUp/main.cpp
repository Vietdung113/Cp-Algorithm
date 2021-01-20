#include<bits/stdc++.h>
using namespace std;
int N,K;
int c[3001];
int t[3001];
int s[3001][101];
bool dd[3001][101];
int solve(int i, int k){
    // cout << cost << endl;
    if (k == 1 && i != N){
        return -1e9;
    }
    if(i==N && k == 1)
    {
        return s[i][k] = c[N];
    }
    if(dd[i][k]) return s[i][k];
    dd[i][k] = true;
    s[i][k] = -1e9;
    for(int j=i+1;j<=min(t[i]+i,N); j++){
        // cout << j << " " << k << " " << s[j][k] << endl;
            // cout << solve(j,k-1,cost+ c[i]) << endl;
        // cout << i << " " << k << " " << s[i][k] << endl;
        // cout << "===================="<<endl;
        s[i][k] = max(s[i][k], solve(j, k - 1) + c[i]);
        // cout << i << " " << k << " " << s[i][k] << endl;
    }
    return s[i][k];
}
int main(){
    cin >> N >>K;
    // cout << N  << " " << K <<endl;
    for(int i=1;i<=N;i++) {
        cin >> c[i];
        // cout << c[i] << " ";
    }
    // cout << endl;
    for(int i=1;i<=N;i++) {
        cin >> t[i];
        // cout << t[i] << " ";
    }
    // cout <<endl;
    // memset(s,0,sizeof s);
    solve(1,K+1);
    if (s[1][K+1]) cout << s[1][K+1];
    else cout << "-1";

}