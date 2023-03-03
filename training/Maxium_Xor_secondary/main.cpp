#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& a){
    int ans = 0;
    vector<int> st;
    for(int i =0;i < a.size(); i++) {
        while(!st.empty() && st.back() < a[i]){
            st.pop_back();
        }
        st.push_back(a[i]);
        if (st.size() >= 2){
            ans = max(ans, st[st.size() - 2] ^ st[st.size() - 1]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n ;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int ans = solve(a);
    reverse(a.begin(), a.end());
    ans = max(ans, solve(a));
    cout << ans << endl;
}