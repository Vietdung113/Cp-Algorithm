//https://codeforces.com/contest/1825/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 1e5+5;

int r[N];
int l[N];
bool visited[N];

int max_left = -1;
int max_right = -1;
int ans=0;

void set_up(int m){
    max_left = m;
    max_right = 1;
    for(int i = 1; i<=m;i++){
        r[i] = i;
        l[i] = i;
        visited[i] = false;
    }
}



void sit_at(int p){
    if(!visited[p]){
        visited[p] = true;
        ans += 1;
    }
}

void join_left(int m){
    if(visited[max_left] && max_left >= 1){
        max_left -= 1;
    }
    if(max_left == 0){
        return;
    }
    ans += 1;
    visited[max_left] = true;
    return;
}
void join_right(int m){
    while(visited[max_right] && max_right <= m){
        max_right += 1;
    }

    if(max_right == m) return;
    visited[max_right] = true;
    ans += 1;

    return;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t<=T ; t++){
        vector<int> inp;
        ans = 0;
        int n,m;
        cin >> n >> m;
        set_up(m);
        int p;
        for(int i = 0; i< n;i++){
            cin >> p;
            inp.push_back(p);
        }
        sort(inp.begin(),inp.end(), greater<int>());
        for(auto p : inp){
            if(p == -1){
                join_left(m);
            }else if (p > 0){
                sit_at(p);
            }else{
                join_right(m);
            }
        }
        cout << ans << "\n";
        // break;

    }
}