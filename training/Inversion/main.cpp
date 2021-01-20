#include<bits/stdc++.h>
using namespace std;
int N;
int a[1000005];
long long ans = 0;
void calc(int l, int r){
    if(l==r) return;
    int mid = (l+r) >> 1 ;
    calc(l,mid);
    calc(mid+1,r);
    for(int i=l; i<=mid; i++){
        int j = lower_bound(a+mid+1, a+r+1, a[i]) - (a+mid+1) ;
        ans += j;
    }
    inplace_merge(a+l, a+ mid +1, a+r+1);
}
int main(){
    cin >> N;
    for(int i =0;i<N;i++){
        cin >> a[i];
    }
    calc(0,N-1);
    cout << ans;
}