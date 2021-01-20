#include<bits/stdc++.h>
using namespace std;
long long h[1000001];
long long L[1000001];
long long R[1000001];
long long n;
stack<long long int> s;
long long solve(){
    memset(L,-1,sizeof L);
    memset(R,-1,sizeof R);
    for(int i=1;i<=n+1;i++){
        while((!s.empty()) && (h[s.top()]> h[i])){
            // cout << "s.top()= " << s.top() << " h[i]= " << h[i]  <<" i= "<<i<< endl;
            R[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    // for(int i =1;i<=n;i++){
    //     cout << R[i] << " "<<endl;
    // }

/////////////////////////////////////////////////////////////////////////////////
    for(int i=n; i>=0;i--){
        while((!s.empty()) && (h[s.top()] > h[i])){
            L[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long int anws = 0;
    for(int i=1;i<=n; i++) anws = max(anws,abs(R[i]-L[i] -1) * h[i]);
    return anws;
}
int main(){
    while (true)
    {
        cin >> n;
        if(n==0) break;
        memset(h,-1,sizeof h);
        for(int i=1; i<=n;i++){
            cin>>h[i];
        }
        h[0] = -1;
        h[n+1] = -1;
        long long anws = solve();
        cout<< anws<<endl;
       
    }
    
}