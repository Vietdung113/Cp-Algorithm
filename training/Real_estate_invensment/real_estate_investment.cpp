#include<bits/stdc++.h>
using namespace std;
int a[301][301];
long long S[301][301] ;
long long S_phay[301] ;
void solution(int r, int c, int l,int t)
{
    // caculated S
    for(int i=1; i <=r;i++){
        for(int j=1;j<=c; j++){
            S[i][j] = - S[i-1][j-1] + a[i][j] - l + S[i-1][j] + S[i][j-1];
        }
    }

    pair<long long, long long> res = make_pair(0,0);
    for(int u=1;u<=r;u++){
        for(int v=u;v<=r;v++){
            for(int i =1;i<= c;i++){
                S_phay[i] = S[v][i] - S[u-1][i];
                }
            int fmin_index = 0;
            for(int j =1;j <=c; j++){
                res = max(res,make_pair(S_phay[j]-S_phay[fmin_index], -1LL * (v-u+1)*(j-fmin_index) * l ));
                if(S_phay[fmin_index] >= S_phay[j]){
                    fmin_index = j ;
                   }
                }
            }
        }
    cout << "#"<<t<<" " << res.first <<" " << (-res.second) << endl;
}
int main()
{
    int T;
    cin >> T;
    for(int t =1; t<=T ; t++){
        int r, c, l;
        cin >> r >> c >> l;
        for(int i=1; i <=r;i++){
            for(int j=1;j<=c; j++){
                cin >> a[i][j];
            }
        }
        solution(r,c,l, t);
    }
    return 0;
}