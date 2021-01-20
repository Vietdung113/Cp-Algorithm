#include<bits/stdc++.h>
using namespace std;
#define N 10005
int n,m;
set<int> A[N];
void euler(){
    stack<int> S, CE;
    S.push(1);
    while (!S.empty())
    {
        int x = S.top();
        if(A[x].size()>0){
            int y = *A[x].begin();
            A[x].erase(y);
            A[y].erase(x);
            S.push(y);
        }
        else
        {
            S.pop();
            CE.push(x);
        }
        
    }
    while (!CE.empty())
    {
        int x = CE.top();
        CE.pop();
        cout << x << " ";
    }
}
int main(){

}