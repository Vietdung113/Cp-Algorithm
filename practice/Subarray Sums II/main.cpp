#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[300000 + 5];
    memset(a, 0, sizeof(a));
    long long n, x;
    map<long long, long long> sum_count;
    cin >> n >> x;
    long long s = 0;
    long long ans = 0;
    sum_count[0] = 1;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        s = s + a[i];
        ans += sum_count[s - x];
        sum_count[s]++;
    }
    cout << ans << endl;
    return 0;
}   