// https://codeforces.com/contest/1863/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
int find_missing_number(int n, int s){
    int k = n * (n+1) / 2 - s;
    return k - s;
}
int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T;t++){
        int n,k;
        cin >> n >>k;
        memset(a, -1, sizeof a);
        int x;
        int s =0;
        for(int i=0;i<n;i++){
            cin >>x;
            s+=x;
        }
        int missing_number = find_missing_number(n, s);
        cout << missing_number << endl;
    }
}
