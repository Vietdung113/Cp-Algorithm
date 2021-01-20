#include<bits/stdc++.h>
using namespace std;

#define N 100005
#define Mod 1000000007

int T,n,k;
int p[N];
int cnt[N];
long long gt[N];
long long rev[N];

void sang_nguyen_to(int n){
    p[1] = 1;
    for(int i=2; (long long) i <= n; i++){
        if(p[i]==0){
            for(int j = i; j<=n; j += i){
                p[j] = i;
            }
        }
    }
}
void ckn(int n, int k){
    for(int i= k+1; i<= n;i++){
        int x = i;
        for(x; x>1;x= x/p[x]){
            cnt[p[x]] +=1;
        }
    }
    for(int i=1;i<=n-k;i++){
        int x = i;
        for(x; x >1; x=x/p[x]){
            cnt[p[x]] -=1;
        }
    }
}
long long pow_x(long long a, long long b){
    if( b==1 ) return a;
    if (b==0) return 1;
    // cout << "a= " << a << "  b= " << b << endl;
    long long x = pow_x(a, b/2);
    x = (x * x) % Mod;
    if(b % 2 == 1){
        return (x * a) % Mod;
    }
    return x;
}
int main(){
    gt[0] = 1;
    rev[0] = 1;
    // cout << rev[1] << endl;

    for(int i = 1;i<=N;i++){
        gt[i] = (gt[i-1] * i) % Mod;
        rev[i] =  pow_x(gt[i], Mod-2);

        // cout << gt[i] << " " << rev[i] << endl;
    }
    cin >> T;
    for(int t=1;t<=T;t++){
        // memset(p,0, sizeof p);
        // memset(cnt, 0, sizeof cnt);

        // cin >> n >> k;
        // sang_nguyen_to(n);
        // ckn(n,k);
        // long long ans =1;
        // for(int i=1;i<=n;i++){
        //     ans = (ans * pow_x(i,cnt[i])) % Mod;
        // }
        // cout << ans ;
        // cout << endl;
        cin >> n >> k;
        long long ans = (((gt[n] * rev[k]) % Mod) * rev[n-k]) % Mod;
        cout << ans << endl;
    }

}