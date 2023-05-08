// https://codeforces.com/contest/1829/problem/A
#include<bits/stdc++.h>
using namespace std;

string s_0 = "codeforces";
string s;
int main(){
    int T;
    cin >> T;
    for(int t =0; t < T; t++){
    cin >> s;
    int ans=0;
    for(int i =0 ; i<10;i++) {
        if (s[i] != s_0[i]) {
            ans +=1;
        }
    }
    cout << ans << '\n';


    }
}