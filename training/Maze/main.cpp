#include<bits/stdc++.h>
using namespace std;

int maze[901][901];
bool visited[901][901];
int n,m,x,y;
struct State{
    int x, y, d;
    State(int _x, int _y,int _d){x= _x; y=_y;d=_d;};
};
int move_st[4][2] = {{-1,0}
             ,{0,-1}
             ,{1,0}
             ,{0,1}};
queue<State> q;
int solver(){
    memset(visited,false,sizeof visited);
    q.push(State(x,y,0));
    while(!q.empty()){
        State s = q.front();
        q.pop();
        if(visited[x][y]) continue;
        for(int i=0;i<4;i++){
            int nextX = s.x + move_st[i][0];
            int nextY = s.y + move_st[i][1];
            if(nextX < 1 || nextX > n || nextY < 1 || nextY > m){
                return s.d+1;
            }
            if(!maze[nextX][nextY]){
                q.push({nextX,nextY,s.d+1});
                // visited[nextX][nextY]= 1;
            }
        }
        visited[x][y] = true;
    }
    return -1;
}
int main(){
    cin >> n >> m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> maze[i][j];
        }
    }
    int anws = solver();
    cout <<anws<<endl;
}