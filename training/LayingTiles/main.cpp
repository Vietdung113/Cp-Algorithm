#include<bits/stdc++.h>
using namespace std;
#define N 99999
int T;
int n,x,y;
int anws = 0;
int c[1<<3][1<<3];
int dp[N][1<<3];
void sinh(int y, int state1, int state2)
{
    // sinh ra cac cach co the tu state 1 sang state 2
    if(y>2){
        c[state1][state2] = 1;
    }
    else
    {
        int b = (state1 >> y) & 1; // getbit(state1,y)
        if(b==0){ // truong hop o y trong can phan dien
            sinh(y+1, state1,state2| (1<<y)); // dat ngang
            if(y+1<=2){ // dat doc
                if(((state1 >> (y+1)) & 1) == 0){
                    sinh(y+2,state1,state2);
                }
            }
            
        }else // o y da dc phu roi nen khong can dien nua
        {
            sinh(y+1, state1, state2);
        }

    }
    
}
int main(){
    cin >> T;
    for(int t=1;t<=T;t++){
        cin >> n >> x >> y;
        // cout << n << " " << x << " " << y << endl;
        // State 1 -> state 2 
        for(int state1=0; state1 < (1<<3); state1++){
            sinh(0,state1,0);
        }
        memset(dp,0,sizeof dp);
        dp[0][7] = 1;
        for(int i=1; i<=n+1; i++){
            for(int state2=0; state2 < (1<<3); state2++){
                    if(i!=x){
                        for(int state1 =0; state1 < (1<<3); state1++){
                            dp[i][state2] += dp[i-1][state1] * c[state1][state2];
                            if(dp[i][state2] >= 1000000007){
                                dp[i][state2] -=  1000000007;
                            }
                        }

                    }else
                    {
                        if((state2 >> (y-1)) & 1) 
                            continue; 
                        int state3 = state2 | (1<<(y-1));
                        for(int state1 =0; state1< (1<<3); state1++){
                            dp[i][state3] += dp[i-1][state1] * c[state1][state2];
                            if(dp[i][state3] >= 1000000007){
                                dp[i][state3] -=  1000000007;
                            }
                        }
                        
                    }
                    
                }
        }
        cout << "#" << t << " " << dp[n+1][0]<<endl;
    }
}