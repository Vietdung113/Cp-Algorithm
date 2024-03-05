#include<bits/stdc++.h>
using namespace std;
// 4 2
// 1 2 3 4
int a[100000 + 5];
int T;
int n, k;
deque<int> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for (int t=1; t<=T; t++){
        cin >> n >> k;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        q.clear();
        // 3 2 4 1
        // 2 2 1
        for (int i=1; i<=n; i++)
        {
            while (q.size() && a[q.back()] >= a[i]) q.pop_back();

            q.push_back(i);

            if (q.front() <= i - k) q.pop_front();

            if (i>=k) cout << a[q.front()] << " ";
        }
        cout << endl;
    }
}