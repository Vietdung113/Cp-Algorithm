#include<bits/stdc++.h>
using namespace std;

#define N 1000005
int n;
pair<int ,int> tasks[N];

int main(){
    cin >> n;
    int d, p;
    for(int i =1;i <= n;i++){
        cin >> d >> p;
        tasks[i] = make_pair(d,p);
    }
    sort(tasks+1, tasks+n+1);
    using pii = pair<int,int>;
    // for(int i =1; i<=n;i++){
    //     cout  << tasks[i].first << " " << tasks[i].second << endl;
    // }
    priority_queue<int,vector<int>, less<int>> q;
    long long ans = 0;
    int j= n;
    for(int i = n; i >=1; i--){
        // cout << j << " " << tasks[j].first << " " << tasks[j].second<<endl;
        while(tasks[j].first >= i && j >=1){
            q.push(tasks[j].second);
            j--;
        }
        if(!q.empty()){
            // cout << i << " " << q.top().first << " " << q.top().second << endl;
            // ans += q.top().second;
            // if (q.top().first >= i){
            ans+= q.top();
            // }
            q.pop();
        }
    }
    cout << ans;
}