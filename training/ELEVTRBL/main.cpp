#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
bool visited[MAX];

int f,s,g,u,d;
int ans = 1e9;
void bfs(){
    queue<pair<int,int>> q;
    q.push({s,0});
    visited[s] = true;
    while (!q.empty())
    {
        int cur = q.front().first;
        int step = q.front().second;
        q.pop();
        if(cur == g){
            ans = min(ans,step);
        }
        int next_move;
        if(cur + u <= f){
            next_move = cur + u;
            if(!visited[next_move]){
                q.push({next_move, step+1});
                visited[next_move] = true;
            }
        }
        if(cur - d >= 1){
            next_move = cur-d;
            if(!visited[next_move]){
                q.push({next_move,step +1});
                visited[next_move] = true;
            }
        }
    }
}
int main(){
    cin >> f >> s >> g >>u >> d;
    // cout << f << " " << s << " " << g << " " << u << " " << d << endl;
    bfs();
    if(ans!=1e9) cout << ans;
    else
    {
        cout << "use the stairs" << endl;
    }
    
}