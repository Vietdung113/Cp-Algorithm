#include<bits/stdc++.h>
using namespace std;
int N; int M;
int a[1001];
vector<int> b;
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }

    for(int i =1;i<=N;i++){
        for(int j =1;j <=N;j++){
            b.push_back(a[i] + a[j]);
        }
    }
    for(int i=1;i<=N;i++){
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    int ans = 0;
    for(int i =0; i< b.size(); i++){
        if (b[i]> M) continue;
        int j = upper_bound(b.begin(), b.end(), M-b[i]) - b.begin();
        if (j==0){
            ans = max(ans, b[i]);
        }else
        {
            ans = max(ans,b[i]+b[j-1]);
        }
        
    }
    cout <<ans;
}