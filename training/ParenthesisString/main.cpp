#include<bits/stdc++.h>
using namespace std;

bool match(char x, char y){
    if(x=='(' && y == ')') return true;
    if(x=='[' && y==']') return true;
    if(x=='{' && y == '}') return true;
    return false;
}
bool check(string s){
    stack<char> k;
    for(int i = 0;i<s.size();i++){
        if((s[i]) == '(' || s[i] == '[' || s[i] == '{') {
            k.push(s[i]);
        }
        else
        {
            if(k.empty()) return false;
            else
            {
                // cout << "top k= "<< k.top() << " s[i]= " << s[i] << endl;
                if(!match(k.top(),s[i])) return false;
                k.pop();
            }
        }
    }
    return k.empty();
}
int main(){
    string s;
    cin >> s;
    // cout <<s<<endl;

    bool anws = check(s);
    cout << anws;
    
}