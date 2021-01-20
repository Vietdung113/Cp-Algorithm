#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000

int T;
int n;
int S[MAX+1];
int E[MAX+1];
int P[MAX+1];

struct Request{
    int s;
    int e;
    int p;
    // Request(int _s, int _e, int _p){s=_s;e=_e;_p=p;};
};
Request R[3001];
int calc(int R1, int R2){
    if((R1==n) && (R2==n)) return -1LL * INFINITY;

    for(int i=1;i < min(R[R1].s, R[R2].s) -1 ; i++){


    }
    return 0;
}


bool comp(Request a, Request b){
    if(a.e < b.e) return true;
    return false;
}
int main(){
    cin >>T;
    for(int t=1;t<=T;t++){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> S[i];
        for(int i=1;i<=n;i++) cin >> E[i];
        for(int i=1;i<=n;i++) cin >> P[i];
        for(int i=1;i<=n;i++) R[i] = {S[i],E[i],P[i]};
        for(int i =1;i<=n;i++){
            cout <<R[i].s << " " << R[i].e << " " << R[i].p <<endl;
        }
        cout << endl;
        sort(R+1,R+n+1,comp);
        for(int i =1;i<=n;i++){
            cout <<R[i].s << " " << R[i].e << " " << R[i].p <<endl;
        }
        int anws = calc(n,n);
        break;

    }
}