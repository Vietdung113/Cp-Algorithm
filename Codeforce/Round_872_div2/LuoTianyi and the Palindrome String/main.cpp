// https://codeforces.com/contest/1825/problem/A
#include<bits/stdc++.h>
using namespace std;

void solve(string s){
    int l = 0;
    int r = s.length() - 1;
    while(l <= r){
        if(s[l] != s[r]) {
            break;
        }
        l++;
    }
    int ans;
    if (l == s.length()) ans=-1;
    else ans = s.length() - 1;
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    string s;
    for(int i = 0; i< t; i++){
        cin >> s;
        solve(s);
    }

}