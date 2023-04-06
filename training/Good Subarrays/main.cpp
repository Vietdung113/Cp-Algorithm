// https://codeforces.com/contest/1398/problem/C
#include<bits/stdc++.h>
using namespace std;

int T;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    for(int t=1; t<=T; t++) {
        long long ans = 0;
        int s = 0;
        map<int, int> cnt;
        cnt[0] = 1;
        cin >> n;
        string str;
        cin >> str;
        for(int i=0; i < n; i++){
            int x = str[i] - '0';
            x--;
            s += x;
            ans += (long long) cnt[s];
            cnt[s]++;
        }
        cout << ans << endl;
    }
}