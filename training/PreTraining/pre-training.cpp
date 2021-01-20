#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// struct Pair {
//     int first;
//     int second;
    
//     Pair(int f, int s){
//         first = f;
//         second = s;
//     };
//     operator < (const Pair other) const {
//         return (first < other.first) || (first == other.first && second < other.second);
//     }
// };
// bool comp(Pair x, Pair y){
//     return (x.first < y.first) || (x.first == y.first && x.second < y.second);
// }
int a[] = {101,234,643,191,9871,53451, 643, 97213, 53451, 12234};
int main(){
    vector<int> v(a, a+10);
    sort(v.begin(), v.end());
    for(auto x: v){
        cout << x << " ";
    }
    cout << endl;
    v.resize(unique(v.begin(), v.end())- v.begin());
    for(auto x: v){
        cout << x << " ";
    }
    cout <<endl;

    vector<int> b(10);
    for(int i = 0; i < 10; i++){
        b[i] = lower_bound(v.begin(),v.end(), a[i]) - v.begin();
        cout << b[i] << " ";
    }
    cout << endl;


}