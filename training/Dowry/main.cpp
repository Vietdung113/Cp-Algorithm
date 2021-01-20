#include<bits/stdc++.h>
using namespace std;
int n, L, R;
pair<long long, long long> t[40];
pair<long long,long long> a[40];

int get_bit(int mask, int idx){
    return (mask >> idx) & 1;
}
void update(int v, int l, int r, int pos, pair<int, int> new_val){
    if(l==r){
        t[v]=  new_val;
    }else
    {
        int m = (l+r) >> 1;
        if(m>=pos){
            update(v +v, l, m, pos, new_val);
        }else
        {
            update(v+v, m+1,r , pos, new_val);
        }
        t[v] = t[]
    }
    
}
vector<pair<int,int>> gen_pair(int n, int p){
    vector<pair<int,int>> res;
    for(int mask =0; mask < pow(2,n); mask++){
        int x=0,y=0;
        for(int i=0;i<log2(n)+1;i++){
            if(get_bit(mask,i)==1){
                // cout << a[i+p].first << " " << a[i+p].second << endl;
                // cout << mask <<endl;
                x += a[i+p].first;
                y += a[i+p].second;
            }
        }
        res.push_back(make_pair(x,y));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    long long w, v;
    cin >> n >> L >> R;

    for(int i =0; i < n ;i++){
        cin >> w >> v;
        a[i] = make_pair(w,v);
    }
    vector<pair<int,int>> S1 = gen_pair(n/2,0);
    vector<pair<int,int>> S2 = gen_pair(n- n/2,n/2);
    sort(S2.begin(),S2.end());
    for(int i=0;i < S2.size(); i++){
        // cout << s.first << " " << s.second <<endl;
        update(1,0,n-1,i,S2[i]);
    }


}