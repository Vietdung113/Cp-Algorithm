#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[] = {2,4,-3,6,-20,7,-2,8,9,5,-6};
int maxSeq(int a[]){
    int s = a[0];
    int anws = s;
    for(int i = 1; i < 11; i++){
        if(s > 0) s = s + a[i];
        else s = a[i];
        anws = max(s,anws);
    }
    return anws;
}
int main(){
    int anws = maxSeq(a);
    cout << anws  <<endl;
}