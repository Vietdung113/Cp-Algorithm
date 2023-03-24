#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int c[17];
int a[17][17];
int n, m;


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <=n; i++) {
        for (int j =1 ; j<=n ;j++) {
            cin >> a[j][i];
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    cout << a[3][5] << endl;
    cout << n << " " << m << endl;
}