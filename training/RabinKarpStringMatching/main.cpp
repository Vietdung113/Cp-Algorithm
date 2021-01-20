#include<bits/stdc++.h>
using namespace std;
const int p = 256;
const int m = 1e9+9;
int countOccurences(string s, string t){
    int S = s.size(); // xau goc
    int T = t.size(); // xau can tim
    vector<long long> p_pow;
    p_pow.push_back(1);
    for(int i=1; i < S ; i ++){
        p_pow.push_back((p_pow.back() * p) % m) ;
    }

    long long h_s[S+1];
    memset(h_s, 0 , sizeof h_s);
    for(int i =0; i< S ; i++){
        h_s[i+1] = (h_s[i] + (int(s[i]) * p_pow[i]) % m) % m ;
    }
    long long h_t = 0;
    for(int i =0 ; i < T; i++){
        h_t = (h_t + (int(t[i])* p_pow[i]) % m) % m ;// hash value of t
    }
    int count = 0;
    for(int i =0; i + T -1 < S; i++){
        long long cur_h = (h_s[i+T] + m - h_s[i]) % m; // hash value in range(i, i+t )
        if(cur_h == h_t * p_pow[i] % m){
            count += 1;
        }
    }
    return count;

}
int main(){
    string s;
    string t;
    getline(cin, t);
    getline(cin, s);
    cout << s << endl << t << endl;
    if (s.size() < t.size()) cout << 0;
    else
    {
        int ans = countOccurences(s,t);
        cout << ans;

    }
    
    }