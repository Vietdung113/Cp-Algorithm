// https://codeforces.com/contest/816/problem/B
#include<bits/stdc++.h>
using namespace std;

#define MAXN 20000006

int a[MAXN];
int d[MAXN];
int s[MAXN];
int n;
int k, q;


void update(int l, int r) {
    d[l]++;
    d[r+1]--;
}
int query(int l, int r) {
    return s[r] - s[l-1];
}
int main(){
    memset(a, sizeof(a), 0);
    cin >> n >> k >> q;
    // cout << n << " " << k << " " << q << endl;
    for(int i=1;i<=n;i++){

        int a, b;
        cin >> a >> b;
        update(a,b);
    }

    memset(s, sizeof s, 0);
    memset(a, sizeof a, 0);

    for(int i =1;i<MAXN;i++){
        a[i] = a[i-1] + d[i];
        s[i] = s[i-1] + (a[i] >=k);
    }
    for(int i =1;i<=q; i++){
        int a, b;
        cin >> a >> b;
        cout << query(a,b) << endl;
    }
}