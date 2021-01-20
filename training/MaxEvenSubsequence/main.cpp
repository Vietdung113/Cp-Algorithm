#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;

int n; 
long long a[N];
long long s[N];
long long smin_odd[N];
long long smin_even[N];

int main(){

    ios_base::sync_with_stdio(false);
    cin >> n;

    // cout << "A: " ;
    for(int i =1;i<=n;i++){
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << endl<<"================"<<endl;
    memset(s,0,sizeof s);
    // cout << "S : ";
    for(int i=1; i <= n;i++){
        s[i] = s[i-1]+a[i];
        // cout << s[i] << " ";
    }
    // cout << endl;
    memset(smin_even,0,sizeof smin_even);
    smin_even[0] = 0;
    // cout << "Smin_even: ";
    for(int i=1;i<=n;i++){
        if(abs(s[i])  % 2==0){
            smin_even[i] = min(smin_even[i-1],s[i]);
        }else
        {
            smin_even[i] = smin_even[i-1];
        }
        // cout << smin_even[i] << " ";
    }
    // cout <<endl;


    memset(smin_odd, 0, sizeof smin_odd);
    smin_odd[0] = 0;
    // cout << "Smin_odd: ";
    for(int i =1;i<=n;i++){
        if(abs(s[i]) % 2 ==1){
            smin_odd[i]= min(smin_odd[i-1],s[i]);
        }else
        {
            smin_odd[i] = smin_odd[i-1];
        }
        // cout << smin_odd[i] << " ";
    }
    // cout << endl;
    long long ans= -1e16;
    for(int i =1; i<= n;i++){
        if(abs(s[i]) % 2==0){
            ans = max(ans,s[i]-smin_even[i-1]);
        }else
        {
            if(abs(s[i] - smin_odd[i-1]) % 2 ==0){
                ans = max(ans,s[i]- smin_odd[i-1]);
            }
            
        }
        // cout<< ans;
        // cout << endl;
    }
    if (ans == -1e16) cout << "NOT_FOUND";
    else
    {
        cout <<ans;
    }
    
    // cout << endl;
    
}
