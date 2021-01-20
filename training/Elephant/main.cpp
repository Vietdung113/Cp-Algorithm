#include<bits/stdc++.h>
using namespace std;
#define DOWN 0
#define UP 1
long long s[2][301][301];
bool visited[2][301][301];
int T;
int N;

long long calc(int a,int b,int k){
    if(a+b == 0) return 1;
    if(visited[k][a][b]) return s[k][a][b];
    visited[k][a][b] = true;
    if(k){
        for(int i =1; i<=b; i++){
            s[k][a][b] += calc(a+i-1,b-i,1-k) ;
            if(s[k][a][b] >= 1000000007){
                s[k][a][b] -= 1000000007;
            }
        }
    }else
    {
        for(int i=1;i<=a;i++){
            s[k][a][b]+=calc(i-1,a+b-i,1-k);
            if(s[k][a][b] >= 1000000007){
                s[k][a][b] -= 1000000007;
            }

    }
            }
    return s[k][a][b];
}
int main(){
    cin >> T;
    for(int t=1;t<=T;t++){
        cin  >> N;
        long long anws = 0;
        memset(visited,false, sizeof visited);
        memset(s, 0, sizeof s);
        for(int i=1;i<=N;i++){
            anws += (calc(i-1,N-i,DOWN) + calc(i-1,N-i,UP)) % 1000000007;
            if(anws>= 1000000007){
                anws -= 1000000007;
            }
        }
        cout << "#" << t << " " << anws<<endl;;
    }
}