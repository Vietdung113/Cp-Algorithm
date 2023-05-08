#include<bits/stdc++.h>
using namespace std;
bool solve(string s, string t) {
    map<char, char> rep;
    map<char, bool> used;

    for(int i = 0; i< s.length(); i++) {
        if (rep.count(s[i])) {
            if (rep[s[i]] != t[i]) return false;
        } else {
            if (used[t[i]]){
                return false;
            }
            rep[s[i]] = t[i];
            used[t[i]] = true;
        }
        return true;
    }


}

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    return 0;
}