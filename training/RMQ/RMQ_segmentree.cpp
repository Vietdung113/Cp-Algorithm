#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int t[N<<2];
int n;
int m;
int a[N];

void update(int v, int l, int r, int pos, int new_val){
    // v quan ly doan tu l-> r 
    // pos la vi tri can update voi gia tri la new_val
    if(l==r){
        t[v] = new_val;
    }else
    {
        int m = (l+r) >> 1;
        if(pos <= m){
            update(v+v, l, m,pos,new_val);
        }else
        {
            update(v+v+1, m+1, r, pos,new_val);
        }
        t[v] = min(t[v+v] , t[v+v+1]); // function dinh nghia o segment tree
    }
}
int get_min(int v, int l, int r, int x, int y){
    if(y <l || r < x){
        return int(1e9+1);
    }
    if(x<=l && r<=y){
        return t[v];
    }
    int m = (l+r) >> 1;
    return min(get_min(v+v,l,m, x, y), get_min(v+v+1, m+1, r, x,y));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        update(1,0,n-1,i,a[i]);
    }
    cin >> m;
    long long ans = 0;
    for(int i =0;i <m;i++){
        int x,y;
        cin >> x >> y;
        ans += get_min(1,0,n-1,x,y);
    }
    cout << ans;

}