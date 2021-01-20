#include<bits/stdc++.h>
using namespace std;
#define N 16
int n;
// int cmin; 
int dd[1<<N][N];
int dp[1<<N][N];
int c[N][N];

int go(int s,int u){
    if(dd[s][u]) return dp[s][u];
    dd[s][u] = true;
    dp[s][u] = 1<<30;
    int remain = s ^ (1<<u); // turn off bit u
    if (remain == 0) dp[s][u] = c[u][0]; 
    // cout << " S = " << s << " remain = " << remain << " u = " << u << "\n";
    for(int v=0; v<=n;v++){
        if((remain>>v) & 1) { // if v hasn't visited yet, then visited v
            dp[s][u] = min(dp[s][u], c[u][v]+ go(remain,v));
            // cout << "s = " << s << " u = " << u << " v = " << v << " go(remain, v) = " << go(remain, v) << " c[u][v] = " << c[u][v] << " dp[s][u]" << dp[s][u] << " rv = " << rv << "\n";
        }
    }
    // cout<<"S: "<<s<<" u: " <<u<< " d[s][u]: "<<dp[s][u]<<endl;
    return dp[s][u];
}
int main(){
    cin >> n;
    // cmin = 1e9;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++)
        {
            int val;
            cin >> val;
            c[i][j] = val;
            // cout << c[i][j] << " ";
            // if (i != j && cmin > c[i][j]) cmin = c[i][j];
        }
        // cout <<endl;
    }
    int anws = go((1<<(n+1))-1,0);
    cout << anws<<endl;
    
    
}