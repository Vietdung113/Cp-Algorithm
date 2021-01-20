#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[] = {4,2,6,3,4,9,7,2,1};
int s[9] = {0};
int longestSubSeq(int a[]){
    s[0] = 1;
    int anws = s[0];
    for(int i = 1 ; i < 9; i++){
        s[i] = 1;
        for(int j =0; j < i ; j++){
            if(a[i] > a[j]) s[i] = max(s[i],s[j]+1); 
        }
        anws = max(anws, s[i]);
    }

     return anws;
}
int main(){
    int anws = longestSubSeq(a);
    cout << anws;
}