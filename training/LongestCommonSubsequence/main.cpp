#include<bits/stdc++.h>
using namespace std;

#define N 10000
#define M 10000

int X[N+1];
int Y[M+1];
int dp[N+1][M+1];
int n,m;

int Try(int n, int m){

    if (dp[n][m] != -1) return dp[n][m];
    if( n<1 || m <1) 
    {
        dp[n][m] = 0;
    }
    else{
        if(X[n]==Y[m]) {
            cout << X[n] << " ";
            dp[n][m] = Try(n-1,m-1) + 1;
        } 
        else dp[n][m] = max(Try(n,m-1), Try(n-1,m));
    }
    return dp[n][m];
}

int lcs(int n, int m){
    for(int i=1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(i==1 && j==1) dp[i][j] = 0;
            else if (X[i] == Y[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> X[i];
    for(int i=1;i<=m;i++) cin >> Y[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j] = -1;
    int anws = lcs(n,m);
    cout <<anws;

}