#include<bits/stdc++.h>
using namespace std;
#define N 502
 
 
int Testcase;
using piul = pair<int,unsigned long long>;
vector<piul> G[N];
int n;
int remove_vertext[N];
unsigned long long w;
unsigned long long d[N][N];
unsigned long long ans[N];
void setMaxForD(){
    for(int i =1; i<=n ;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j] ==0 && i!=j){
                d[i][j] = 1e15;
            }
        }
    }
}
void solve(){
    // setMaxForD();
    // vector<int> remove;
    memset(ans, 0, sizeof ans);
    for(int k=n;k>0;k--){
        // int v = remove_vertext[k];
        int k_ = remove_vertext[k];
        for(int i=n;i>0;i--){
            int i_ = remove_vertext[i];
            for(int j=n;j>0;j--){
                int j_ = remove_vertext[j];
                // cout << "d[" << i_ << "][" << j_ << "]= " << d[i_][j_] << " d[i][k]= " << d[i_][k_] << " d[j_][k_]= " << d[j_][k_] << endl;
                if(d[i_][k_] <1e15 && d[k_][j_] <1e15 )
                {
                    d[i_][j_] = min(d[i_][j_], d[i_][k_]+ d[j_][k_]);
                }
                if(i>=k && j >=k && d[i_][j_] < 1e15){
                    ans[k] = max(ans[k], d[i_][j_]);
                }
            }
        }
        // remove.push_back()
        // cout << k << endl;
        // cout << ans[k] << endl;
    }
}
int main(){
    cin >> Testcase;
    for(int T=1;T<=Testcase;T++){
        cin >> n; 
 
        memset(d,0, sizeof d);
        for(int i=1; i<= n;i++){
            int v; 
            cin >> v;
            remove_vertext[i] = v;
        }
        // cout << endl;
        for(int i=1;i<=n;i++){
            for(int j =i+1; j<=n;j++){
                cin >> w;
                d[i][j] = w;
                d[j][i] = w;
 
            }
        }
 
        setMaxForD();
        // for(int i =1;i<=n;i++){
        //     for(int j =1 ; j<=n;j++){
        //         cout << d[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        solve();
        cout << "#" << T << " ";
        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        // for(int i =1;i<=n;i++){
        //     cout << "vertex: " << i << endl;
        //     for(piul k :G[i]){
        //         cout << k.first << " " << k.second << endl;
        //     }
        //     cout << endl;
        // }
 
        // break;
    }
}