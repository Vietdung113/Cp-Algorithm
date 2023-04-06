#include<bits/stdc++.h>

using namespace std;
int n ;
int a[100005];

int main() {
    cin >> n;
    for(int i =0; i<n;i++){
        cin >> a[i];
    }   

    int ans = 0;
    
    int j ;
    int min_val;
    int max_val;
    for (int i=0; i < n; i++){
        j= i;
        min_val = a[i];
        max_val = a[i];
        while(j < n && max_val - min_val <= 1) {
            max_val = max(max_val, a[j]);   
            min_val = min(min_val, a[j]);
            if(max_val - min_val <= 1) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
    }
    cout << ans;
}