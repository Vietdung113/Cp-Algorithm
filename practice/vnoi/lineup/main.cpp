// https://oj.vnoi.info/problem/fcb051_lineup
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +5;

int main() {
    int n;
    cin >>n ;
    int total = 0;
    int l = 0;
    bool need_swap = false;
    for(int i =1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        l += a;
        l = l % 2;
        total += a + b; 
        total = total % 2;
    }
    if (total % 2 == 0 && l % 2 == 1) {
        cout << "1\n";
    }else if (total % 2 == 0 && l % 2 ==0){
        cout << "0\n";
    }else{
        cout << "-1\n";
    }
}