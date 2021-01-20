#include<bits/stdc++.h>
using namespace std;

unsigned int check[68000000] = {0};
void turnOn(int index, int b){
    check[index] = check[index] | (1LL<<(b));
}
bool getState(int index, int b){
    if(check[index] & (1LL<<(b))) return true;
    return false;

}
void turnOff(int index, int b){
    check[index] = (check[index]  & ~(1LL<<(b)));
}
int main()
{
    unsigned int Q, S1, A, B;
    cin >> Q >> S1 >> A >> B;
    unsigned int S = S1;
    unsigned long int anws = 0;
    for(int i =1;i<=Q;i++){
        unsigned int v = S >> 1;
        unsigned int index = v >> 5;
        unsigned int b = v & 31;
        unsigned int state = getState(index,b);
        if(S % 2 == 0)
        {
            if(state){
                turnOff(index, b);
                anws -= v;
            }
        }
        else
        {
            if(!state){
                turnOn(index,b);
                anws += v;
            }
        }
        S = A * S + B;
    }
    cout << anws;
}