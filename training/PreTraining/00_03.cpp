#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int n = 3;
int x[n+1];
void solution(){
    for(int i=1;i<=n;i++) cout <<x[i];
    cout <<endl;
}
bool visited[n+1] = {false};
bool check(int v){
   return !visited[v];
}
void Try(int k,int idx){
    for(int v = idx; v <=n; v++){
        if (check(v)){
            x[k] = v;
            visited[v] = true;
            if (k==n) solution();
            else Try(k+1,v+1);
            visited[v] = false;
        }
    }
}
int main(){
    Try(1,1);
}