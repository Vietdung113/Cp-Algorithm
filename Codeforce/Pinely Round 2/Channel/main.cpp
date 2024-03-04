// https://codeforces.com/contest/1863/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    int n,a,q;
    for (int t=1; t<=T; t++){
        cin >> n >> a >> q;
        int onl = 0;
        int off = 0;
        int remain = a - n;
        int is_yes = false;
        for (int i = 0; i<q;i++){
            char c;
            cin >> c;
            if (remain >= 0 && is_yes==false){
                is_yes = true;
            }
            if(c=='-'){
                remain -=1;
                off += 1;
            }else {
                remain +=1;
                onl+=1;
            }
            if (remain >= 0 && is_yes == false) {
                is_yes = true;
            }
        }
        // cout << remain << endl;
        if (is_yes) cout << "YES" << endl;
        else{
            if(a + onl - n < 0) cout << "NO" << endl;
            else cout << "MAYBE" << endl;
        }

    }
}