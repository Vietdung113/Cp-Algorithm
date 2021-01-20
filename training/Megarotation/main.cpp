#include<bits/stdc++.h>
using namespace std;
string s;
string t;
string n;
vector<long long> p_pow;
int p =31;
long long m = 1e9 + 9;

void caclPow(){
    p_pow.push_back(1);
    for(int i=1; i < t.size() ; i ++){
        p_pow.push_back((p_pow.back() * p) % m) ;
    }
}

string convertWithD(string s,int d){
    for(int i=0;i< s.size(); i++){
        if(s[i] + d > 'z') {
            s[i] = 'a' + (s[i] + d - 'z' - 1);
        }
        else if(s[i] + d < 'a') {
            s[i] = 'z' - ('a' - s[i] -d - 1);
        }
        else
        {
            s[i] = s[i] + d ;
        }
    }
    return s;
}
void solve(){
    // cout << "t= " << t << endl;
    p_pow.push_back(1);
    for(int i=1; i < t.size() ; i ++){
        p_pow.push_back((p_pow.back() * p) % m) ;
    }

    // cout << "p_pow: " ;
    // for(int i =0;i < t.size();i++){
    //     cout << p_pow[i] << " ";
    // }
    // cout <<endl;

    long long h_t[t.size() + 1]; // hash array of t 
    memset(h_t, 0, sizeof h_t);
    // cout << "h_t = ";
    for(int i =0; i < t.size(); i++){
        h_t[i+1] = (h_t[i] + (int(t[i]) * p_pow[i]) % m) % m ;
        // cout << h_t[i+1] << " " ;
    }
    // cout << endl;
    int l = -1;
    int d_ans;
    bool check = false;
    string k;
    for(int d=-13; d<=13;d++){
        if (check) {
            break;
        }
        k  = convertWithD(s,d);
        long long h = 0;
        for(int i =0 ; i < k.size(); i++){
            h = (h + (int(k[i])* p_pow[i]) % m) % m ;// hash value of t
        }
        for(int i =0; i + k.size()-1 < t.size();i++){
            if (check) {
                // cout << "d= " << d << " k= " << k << endl;

                break;
            }
            long long cur_h = (h_t[i+k.size()] - h_t[i] + m ) % m;
            if(cur_h == h * p_pow[i] % m){

                // cout << "d= " << d << " k= " << k  << "   curr_h= " << cur_h << " h = " << h<< endl;
                l = i;
                d_ans = d;
                check = true;
            }
        }
    }
    if (l==-1){
        cout << "Impossible";
    }
    else
    {
        cout << "Success" << endl;
        cout << l << " " << d_ans <<endl;
    }
    
}
int main(){
    cin >> n; 
    string tmp;
    getline(cin,tmp);
    getline(cin,s);
    getline(cin,t);
    
    // cout << k << endl;
    if(s.size()!=t.size()) cout << "Impossible";
    else
    {
        t += t;
        solve();
    }
    
}