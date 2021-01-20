#include<bits/stdc++.h>
using namespace std;
int n;

struct Point{
    int x,y;
    Point(int _x, int _y){x = _x; y=_y;}
    Point(){}
};
struct Segment{
    Point a,b;
    Segment(Point _a, Point _b){a=_a; b=_b;}
    Segment(){}
};
struct Line{
    double a, b, c;
    Line(double _a, double _b, double _c){
        a= _a;
        b =_b;
        c =_c; 
    }
    Line(){}
};
vector<Point> p;
vector<Segment> s;

void input(){
    cin >> n;
    int x,y;
    for(int i =0 ;i < n;i++){
        for(int j= 0;j<4;j++){
            if(j%2==0) cin >> x;
            else
            {
                cin >> y;
                p.push_back({x,y});
            }
        }
    }
    for(int i = 0 ; i< p.size(); i++){
        if(i%2==1){
            s.push_back({p[i-1],p[i]});
        }
    }
    for(int i=0;i<s.size();i++){
        cout << s[i].a.x << " " << s[i].a.y << " " <<s[i].b.x <<" " << s[i].b.y <<endl;
    }
}
double crossProd(Point a, Point b){
    return a.x * b.y - b.x * a.y;
}
bool isCross(Segment s1,Segment s2){
    double d1 = crossProd(Point({s1.b.x - s1.a.x, s1.b.y - s1.a.y}), Point({s2.a.x - s1.a.x, s2.a.y - s1.a.y}));// AB x AC
    double d2 = crossProd(Point({s1.b.x - s1.a.x, s1.b.y - s1.a.y}), Point({s2.b.x - s1.a.x, s2.b.y - s1.a.y}));// AB x AD
    double d3 = crossProd(Point({s2.b.x - s2.a.x, s2.b.y - s2.a.y}), Point({s1.a.x - s2.a.x, s1.a.y - s2.a.y}));// CD x CA
    double d4 = crossProd(Point({s2.b.x - s2.a.x, s2.b.y - s2.a.y}), Point({s1.b.x - s2.a.x, s1.b.y - s2.a.y})); // CD x CB
    if(d1*d2 <= 0 && d3 * d4 <=0 ) return true;
    return false;
}
Line findLine(Point a, Point b){

}
Point findIntersec(Segment a, Segment b){
    Line l1 = findLine(a.a, a.b); // find line go through segment 1 (AB)
}
int solve(){
    int ans =0;
    for(int i=0; i < s.size(); i++){
        int count_intersec = 0;
        set<Point> k;
        k.insert(s[i].a);
        k.insert(s[i].b);
        for(int j=0; j<s.size();j++){
            if(i==j) continue;
            if(isCross(s[i],s[j])){
                Point c = findIntersec(s[i], s[j]);
            }
        }
    }
}
int main(){
    input();
}