#include<bits/stdc++.h>
using namespace std;
struct State{
    int b1,b2,step;
    State(int _b1, int _b2, int _step) {b1=_b1; b2=_b2; step =_step;};
};
int visited[901][901];
int a,b,c;
queue<State> q;
int solve(){
    memset(visited,0, sizeof visited);
    q.push({0,0,0});
    while(!q.empty()){
        State s = q.front(); q.pop();
        if(s.b1 == c || s.b2 == c) return s.step;
        if (visited[s.b1][s.b2]) continue;
        q.push({a,s.b2,s.step+1});
        q.push({0,s.b2,s.step+1});
        q.push({s.b1,b,s.step+1});
        q.push({s.b1,0,s.step+1});
        if(s.b1 < a){
            q.push({min(a,s.b1 + s.b2),max(0,s.b2+s.b1-a),s.step+1});
        }
        if(s.b2 < b) q.push({max(0,s.b1+s.b2-b), min(b,s.b2+s.b1), s.step+1});

        visited[s.b1][s.b2] = true;
        // }
    }
    return -1;
}
int main(){
    cin >> a >> b >>c;
    int anws = solve();
    cout << anws;

}