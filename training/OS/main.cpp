#include<bits/stdc++.h>
using namespace std;
#define M 1000009
#define N 1000005

pair<int,int> a[N];
pair<int, int> a_[N];
int n,m;
int next_fill[N+N];

int fill_next(int l, int r, bool &check){
    // cout << l << " " << r << endl;
    // cout << (next_fill[l]==0) << endl;
    if(l > r){
        return l;
    }
    if(next_fill[l] == 0){
        // cout << fill_next(l+1,r,check)<<endl;
        return next_fill[l] = fill_next(l+1,r,check);
    }
    else
    {
        check = true;
        return next_fill[l] = fill_next(next_fill[l], r, check);
    }
}
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    cin >> n;
    int x, y;
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        a[i] = make_pair(x,y);
        v.push_back(x);
        v.push_back(y);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());

    for(int i=1; i <=n ;i++){
        int x = lower_bound(v.begin(),v.end(),a[i].first) - v.begin();
        int y = lower_bound(v.begin(),v.end(), a[i].second) - v.begin();
        a_[i] = make_pair(x,y);
    }
    bool check;
    int ans =0 ;
    for(int i=n;i >=1;i--){
        check = false;
        int k = fill_next(a_[i].first, a_[i].second, check);
        // cout << check << endl;
        if(!check){
            ans +=1;
        }
    }
    cout << ans;
}