#include<bits/stdc++.h>
using namespace std;
int a[9][9];
int visited[9][9];
int LEFT=0;
int DOWN=1;
int RIGHT=2;
int UP=3;
int move_x[] = {-1, 0, 1, 0};
int move_y[] = {0, 1, 0, -1};
int ans = 0;

int get_direction(int d){
    if( d >= 4){
        d -= 4;
    }
    if (d < 0){
        d += 4;
    }
    return d;

}
void dfs(int x, int y, int direction, int n_step){

    // cout << x << " " << y << " direction: " << direction << " n_step: " << n_step << endl;

    if(visited[x][y] || x > 8 || y >8 || x < 1 || y < 1) {
        ans = max(ans, n_step - 1);
        return;
    }

    visited[x][y] = true;
    // try go next
    int next_x = x + move_x[direction];
    int next_y = y + move_y[direction];

    if (a[next_x][next_y] == -1 || next_x < 1 || next_x > 8 || next_y < 1 || next_y > 8){
        for(int i=-1; i < 2; i+= 2) {
            // turn left-right
            direction += i;
            direction = get_direction(direction);
            int new_x = x + move_x[direction];
            int new_y = y + move_y[direction];

            dfs(new_x, new_y, direction, n_step + 1);
            direction -= i;
            direction = get_direction(direction);
        }
    }else{
        dfs(next_x, next_y, direction, n_step+1);

    }

    visited[x][y] = false;
}

int main() {
    int n;
    cin >> n;
    for(int i =0; i< n;i ++){
        int x,y;
        cin >>x >>y ;
        // blocking
        a[x][y] = -1;
    }
    dfs(1, 1, 1, 0);
    cout << ans << endl;
}