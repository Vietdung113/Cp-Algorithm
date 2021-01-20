#include<bits/stdc++.h>
using namespace std;
#define N 1005


// int nxt_w[N+N];
// int nxt_h[N+N];
int n;
int l_w[N];
int r_w[N];
int d_h[N];
int u_h[N];
int W,H;
int nxt[N+N][N+N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int a, int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    // visited[a][b] = true;
    nxt[a][b] = 1;
    while (!q.empty()){
        pair<int,int> t = q.front();
        q.pop();
        for(int i = 0 ; i <4 ;i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x <0 || x >= H ) continue;
            if(y < 0 || y >= W) continue;
            // cout << x << " " << y << endl;
            if(nxt[x][y] ==0){
                q.push(make_pair(x,y));
                nxt[x][y] = 1;
                // visited[x][y] = true;
            }
        }
    }
 
}
int fill(int y, int l, int r){
    if(l>=r){
        return l;
    }
    if(nxt[y][l] == 0){
        return nxt[y][l] = fill(y, l+1, r);
    }else
    {
        return nxt[y][l] = fill(y, nxt[y][l], r);
    }
}

int find(int p[], int v){
    if(v==p[v]){
        return v;
    }
    return p[v] = find(p, p[v]);
}

int main(){
    vector<int> v_w;
    vector<int> v_h;
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> W >> H;
    cin >> n;
    v_w.push_back(W);
    v_h.push_back(H);
    v_w.push_back(0);
    v_h.push_back(0);
    for(int i =0; i< n;i++){
        cin >> l_w[i] >> d_h[i] >> r_w[i] >>u_h[i];
        // cout << l_w[i] << " ";
        // cout << r_w[i] << " ";
        v_w.push_back(l_w[i]);
        v_w.push_back(r_w[i]);
        v_h.push_back(d_h[i]);
        v_h.push_back(u_h[i]);
    }
    // cout << endl << endl;
    sort(v_w.begin(),v_w.end());
    v_w.resize(unique(v_w.begin(),v_w.end()) - v_w.begin());
    // for(int i : v_w){
    //     cout << i << " ";
    // }
    // cout << endl;
    sort(v_h.begin(),v_h.end());
    v_h.resize(unique(v_h.begin(),v_h.end()) - v_h.begin());
    // for(int i: v_h){
    //     cout << i << " ";
    // }
    // cout <<endl;
    for(int i=0;i< n;i++){
        l_w[i] = lower_bound(v_w.begin(), v_w.end(), l_w[i]) - v_w.begin();
        r_w[i] = lower_bound(v_w.begin(), v_w.end(), r_w[i]) - v_w.begin();
        d_h[i] = lower_bound(v_h.begin(), v_h.end(), d_h[i]) - v_h.begin();
        u_h[i] = lower_bound(v_h.begin(), v_h.end(), u_h[i]) - v_h.begin();
    }
    W = lower_bound(v_w.begin(), v_w.end(), W) - v_w.begin();
    H = lower_bound(v_h.begin(), v_h.end(), H) - v_h.begin();

    // cout << W << endl;
    // cout << H << endl;
    for(int i =0; i < n;i++){
        for(int j = d_h[i]; j < u_h[i]; j++ ){
            fill(j, l_w[i], r_w[i]);
        }
        // for(int i =0; i < H; i++){
        //     for(int j =0; j < W; j++){
        //         cout << nxt[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;


    }
    // for(int i =0; i < H; i++){
    //     for(int j =0; j < W; j++){
    //         cout << nxt[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;
    int ans = 0;
    for(int i =0; i < H; i++){
        for(int j =0; j < W; j++){
            // cout << i << " " << j << " " << nxt[i][j] << endl;
            if(nxt[i][j] == 0){
                bfs(i,j);
                ans+=1; 
                // for(int i =0; i < H; i++){
                //     for(int j =0; j < W; j++){
                //         cout << nxt[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl << endl;
            }
        }
    }

    cout << ans;
}