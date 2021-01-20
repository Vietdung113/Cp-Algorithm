#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 +1;
const int MAX_M = 30;
int n;
int m;
int a[N];
int M[MAX_M][N];
pair<int,int> T[N];
int rmq(int l, int r){
    int k = log2(r-l+1);
    if(a[M[k][l]] <= a[M[k][r-(1<<k) +1]]){
        return M[k][l];
    }
    return M[k][r-(1<<k)+1];
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    int l,r;
    int min_index;

    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        M[0][i] = i;
    }
    for(int j=1; (1<<j) <= n; j++){
        for(int i =0; i + (1<<j) - 1 < n; i++){
            if( a[M[j-1][i]] < a[M[j-1][i+ (1<<(j-1))]]) {
                M[j][i] = M[j-1][i];
            }
            else
            {
                M[j][i] = M[j-1][i+(1<<(j-1))];
            }
        }
    }
    cin >> m; 
    for(int i=0;i<m;i++){
        cin >> l >> r;
        T[i] = make_pair(l,r);
    }
    for(int i=0;i<m;i++){
        min_index = rmq(l,r);
        ans += a[min_index];

    }

    cout << ans;

}