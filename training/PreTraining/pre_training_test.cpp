#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Pair
{
    int c;
    int s;
    int i;
    Pair(int s_class, int score, int index) 
    {
        c = s_class;
        s = score;
        i = index;

    }
    operator < (const Pair other){
        if (c < other.c) return true;
        if (c == other.c  && s < other.s) return true;
        // if (c == c && s == s && i < other.i) return true;
        return false;
    }
};

int main(){
    vector<int> c;
    vector<int> s;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m; i++){
        int t;
        cin >> t;
        c.push_back(t);
    }
    for( int j=0; j < m; j ++){
        int t;
        cin >> t;
        s.push_back(t);
    }

    vector<Pair> a;
    for(int i =0;i < m; i++){
        a.push_back(Pair(c[i],s[i],i));
    }
    sort(a.begin(),a.end());
    for (int i =0; i < a.size(); i++)
    {
        cout <<"Class: " << a[i].c << " Scores: " << a[i].s<<" Index: "<< a[i].i << endl ;
    }
    cout << endl;
    pair<int,int> anws[10000];
    int count = 0;
    for (int i =1 ; i <= n; i++){
        int k = lower_bound(a.begin(), a.end(), Pair(i,10000, 1000)) - a.begin();
        for(count ; count < k; count++ ){`
            anws[a[count].i] = make_pair(count, k - count);
            cout << count << " " << k -count << endl;
        }
    }

}