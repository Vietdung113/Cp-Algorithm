#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n;
int a[N];
int T[N];
int get(int i){
    int w= 0;
    for(;i; i -=i &(-i)){
        w+=T[i];
    }
    return w;
}
void add(int i, int val){
    for(;i <= n; i+= i &(-i)){
        T[i] += val;
    }
}

int main(){
    cin >> n;
    for(int i =0;i <n;i++){
        cin >> a[i];
    }
    long long ans = 0; 
    for(int i =0;i <n ;i++){
        cout << "get(n)= " << get(n) << endl;
        cout << "get(i)= " << get(a[i]) << " a[i]= " << a[i] << endl;
        // cout << get(n) -  get(a[i]) << endl;

        ans += get(n) -  get(a[i]);
        add(a[i],1);
    }
    cout << ans;
}