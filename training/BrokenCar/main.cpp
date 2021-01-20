#include<bits/stdc++.h>
using namespace std;

#define N 502
#define FORWARD 1
#define TURNLEFT 0
#define TURNRIGHT 2
int Testcase;
pair<int,int> start;
pair<int,int> end_point;
int M[N][N];
int n;
string s[N];
bool visited[N][N][4][3][2];
struct State{
    int x,y, d,t, k,step;
};
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int h[] = {0,1,2};
int ans;
bool check(State s){
   if(s.x < 1 || s.x > n || s.y < 1 || s.y > n) return false;
    if(M[s.x][s.y] ==0 && s.k < 2 && visited[s.x][s.y][s.d][s.t][s.k] == false) return true;
    else
    {
        return false;
    }
}
State gen_next_state(State s, int h){
        // cout << s.x << " " << s.y << " " << s.d << " " << s.t << " " << s.k << " " << h <<  endl;

        int d_ = (s.d + h + 3) % 4;
        int x_ = s.x + dx[d_];
        int y_ = s.y + dy[d_];
        int t_;
        int k_;
        if(h == FORWARD){
            t_ = s.t;
            k_ = s.k;
        }else
        {
            t_ = h;
            if(h != s.t){
                k_ = 0;
            }else
            {
                k_ = s.k +1;
            }
        }
    return {x_, y_, d_,t_, k_, s.step +1};
}
bool check_finish(State s){

    if(s.x == end_point.first && s.y == end_point.second){
        // cout <<s.x << " " << s.y << endl;
        ans = min(ans, s.step);
        return true;
    }
    return false;
}
void bfs(){
    queue<State> q;
    State s = {start.first, start.second, FORWARD, FORWARD, 0 ,0};
    for(int i=0;i < 4;i++){
        if(M[s.x+ dx[i]][s.y +dy[i]]!=0) continue;
        if(s.x + dx[i] < 1 || s.x + dx[i] > n || s.y + dy[i] < 1 || s.y + dy[i] > n){
            continue;
        }
        else
        {  
            q.push({s.x+dx[i], s.y + dy[i], i, FORWARD, 0, 0});
            visited[s.x+dx[i]][s.y+dy[i]][i][FORWARD][0] = true;
        }
        
    }
    while (!q.empty())
    {
        State s = q.front();
        q.pop();
        for(int next_d : h){
            State next_s = gen_next_state(s,next_d);
            if(check(next_s)){
                // cout << next_s.x << " " << next_s.y << " " << next_s.d << " " << next_s.t << " " << next_s.k << " " << next_s.step <<  endl;
                // cout << next_s.x << " " << next_s.y << endl;
                q.push(next_s);
                visited[next_s.x][next_s.y][next_s.d][next_s.t][next_s.k] = true;
                if(check_finish(next_s)) return ;
            }
        }
        // cout << s.x << " " << s.y << " " << s.d << " " << s.t << " " << s.k << " " << s.step << endl;
    }
    // cout << end_point.first << " " << end_point.second << endl;
   
}
int main(){
    cin >> Testcase;
    for(int t=1; t<=Testcase; t++){
        cin >> n;
        for(int i=1; i<=n;i++){
            cin >> s[i];
            // cout << s[i] << endl;
        }

        for(int i =1 ; i <= n; i++){
            for(int j =0 ; j<n ;j++){
                if(s[i][j] == '1' ){
                    // cout << s[i][j] << endl;
                    M[i][j+1] = 1;
                }
                if(s[i][j] == '0'){
                    M[i][j+1] = 0;
                }
                if(s[i][j] == 'S'){
                    M[i][j+1] = 1;
                    start = make_pair(i,j+1);
                }
                if(s[i][j] =='T'){
                    M[i][j+1] = 0;
                    // cout << M[i][j+1] << " " << i << " " << j+1 << endl;
                    // cout << s[i][j] << endl;
                    end_point = make_pair(i,j+1);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j =1; j<=n;j++){
        //         cout << M[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        memset(visited, 0 ,sizeof visited);
        ans = 1e6;
        bfs();
        if(ans == 1e6){
            cout << "#" << t << " -1" <<endl;
        }
        else
        {
            cout << "#" << t <<  " " << ans << endl;
        }
    
        // break;
    }
}