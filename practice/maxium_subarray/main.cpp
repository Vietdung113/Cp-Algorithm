// https://cses.fi/problemset/task/1643

#include<bits/stdc++.h>
using namespace std;
int n;
long long s[1000005];
long long m[1000005];
 
int main(){
    int k;
    cin >> n;
    s[0] = 0;
    m[0] = 0;
   for(int i=1;i<=n;i++)
    {
        cin >> k;
        s[i] = s[i-1] + k;
        m[i] = min(m[i-1], s[i-1]);
    }
    // cout << endl;
    long long ans = - INT_MAX;
    for(int i=1;i<=n;i++){
        ans = max(s[i] - m[i], ans);
    }
    cout << ans<< endl;

}