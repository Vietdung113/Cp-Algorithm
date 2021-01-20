#include<bits/stdc++.h>
using namespace std;
#define N 100005

int node[N * 100][4];
int cnt[100 * N];
int k;
int T;
int n;
string s;
int command;
int root;


int create_node(){
    k++;
    memset(node[k], 0, sizeof node[k]);
    cnt[k] = 0 ;
    return k;
}
void add(string s){
    int p = root;
    for(char c: s){
        int i = c - 'A';
        if(node[p][i]==0){
            node[p][i] = create_node();
        }
        p = node[p][i];
        cnt[p]++;
    }
}
void del(string s){
    int p = root;
    for(char c: s){
        int i = c - 'A';
        p = node[p][i];
        cnt[p]--;
    }
}
int find(string s){
    int p = root;
    for(char c: s){
        int i = c - 'A';
        p = node[p][i];
    }
    return cnt[p];
}

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){

        cin >> n;
        k = 0 ;
        root = create_node();
        int ans = 0;
        for(int i =0 ;i <n ;i++){
            cin >> command;
            cin >> s;
            if(command == 1){
                add(s);
            }else if (command == 2)
            {
                del(s);
            }else
            {
                ans += find(s);
            }
        }
        cout << "#" << t << " " << ans<<endl;
    }
}