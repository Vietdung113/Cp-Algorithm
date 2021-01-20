#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define M 1000005
int a[N];
int b[N];
int T1[N];
int T2[N];


int k[M];
int l[M];
int r[M];
int n,m;

struct Stages{
    int l,r,x,y;
} st[M];

struct Query{
    int l, r, k ,id;
};
vector<Query> query;


void add(int T[], int idx, int val){
    for(; idx<=n; idx+= idx&(-idx)){
        T1[idx] += val;
    }
}
bool finish(){
    for(int i =1; i <=m; i++){
        if(query[i].l +1  < query[i].r) return false;
    }
    return true;
}
bool comp_k(Query q1, Query q2){
    return q1.k < q2.k;
}
bool comp_id(Query q1, Query q2){
    return q1.id < q2.id;
}
void update(int l, int r , int x, int y){
    add(T1,l, y);
    add(T1, r+1, -y);
    add(T2, l, -l *y + x);
    add(T2, r+1, l*y - x);
}
int get_signle(int T[], int i){
    int w = 0;
    for(;i>0; i-= i &(-i)){
        w += T[i];
    }
    return w;
}

int increase_sum(int idx){
    return get_signle(T1,idx) * idx - get_signle(T2,idx);
}

void solve(){
    for(Query q : query){
        q.k = (q.r + q.l) / 2;
    }
    sort(query.begin(), query.end(), comp_k);
    int j = 1;
    for(Query q: query){
        while(j<=m && j <= q.k){
            update(st[j].l, st[j].r, st[j].x, st[j].y);
            j++;
        }
        int s = increase_sum(q.id);
        if(a[q.id] + s >= b[q.id]){
            q.r = q.k;
        }else
        {
            q.l = q.k;
        }
    }
}
int main(){
    cin >> n; 
    for(int i =1; i <=n;i++){
        cin >> a[i] ;
        cout << a[i] <<" ";
    }
    cout << endl;

    for(int i =1; i <= n;i++){
        cin >> b[i] ;
        cout << b[i] <<" ";
    }
    cin  >> m;
    for(int i=1 ; i<= m;i++){
        int l, r, x,y;
        cin >> l >> r >> x>> y;
        st[i] = {l,r,x,y};
        query.push_back({0,m+1,0,i});
        // query[i] = {0,m+1, 0, i};
    }
    while(!finish()){
        solve();
    }
    sort(query.begin(), query.end(), comp_id);
    for(Query q: query){
        cout << q.id << " ";
    }
}