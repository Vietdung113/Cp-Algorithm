#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ml = -1, mr =-1, mlr = -1;
int a[] = {2,4,-3,6,-20,7,-2,8,9,5,-6};
int maxLeft(int a[], int l ,int r){
    int t =0;
    int max = -100000000;
    for(int i=r; i>=l;i--){
        t =t +a[i];
        if (t > max) max = t;
    }
    return max;
}
int maxRight(int a[], int l, int r){
    int t = 0;
    int max = -1000000000;
    for(int i =l; i<=r;i++){
        t = t + a[i];
        if (t >max) max =t;
    }
    return max;
}
int maxSeq(int a[], int l, int r){
    if(l==r) return a[l];
    int m = (l+r) /2 ;
    ml = maxSeq(a,l,m);
    mr = maxSeq(a,m+1,r);
    mlr = maxLeft(a,l,m) + maxRight(a,m+1,r);
    int anws = max({ml,mr,mlr});
    return anws;
}

int main(){
    int anws = maxSeq(a,0,10);
    cout << anws;
}