#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 3;
int x[N];
int count = 0;
void solution(){
    for(int i =0; i <N;i++){
        cout << x[i];
    }
    cout <<endl;
}

bool check(int v, int k){ 
    if(k==0) return true;
    if (x[k-1] == 1 && v == 1) return false;
    return true;
}

void Try(int k){
    for(int v =0; v<=1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k== N-1) solution();
            else Try(k+1);

        }
    }
}
int main(){
    Try(0);
}