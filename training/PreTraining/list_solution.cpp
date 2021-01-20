#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int m = 5, n =3;
int x[n];
int t=0;
bool check(int v, int k){
   if(k < n- 1) return true;
   return  t+v == m;
}
void solution(){
    for(int i=0;i<n;i++){
        cout << x[i] << " ";
    }
    cout <<endl;
}
void Try(int k){
    for(int v=1; v <= m - t -n + k + 1; v++){
        if(check(v, k)){
            x[k] = v;
            t = t + v;
            if(k == n-1) solution();
            else Try(k+1);
            t = t - v;
        }
    }
};
int main(){
    int t = 0;
    Try(0);
}