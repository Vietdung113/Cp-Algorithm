#include<bits/stdc++.h>
using namespace std;
#define NGUOC 0
#define CUNG 1
int N;
int T;
int Q;
int x,y;
 
struct Point{
    int x,y;
    Point(int _x, int _y){
        x= _x; 
        y = _y; 
    }
    Point(){}
};
Point P0;
 
bool comp(Point a, Point b){
    if(a.y < b.y) return true;
    if(a.y == b.y) {
        if(a.x <= b.x) return true;
    }
    return false;
}
int crossProd(Point A, Point B){
    if (1LL * A.x * B.y > 1LL * B.x * A.y) return 1;
    else if (1LL * A.x * B.y > 1LL * B.x * A.y)
    {
        return 0;
    }
    return -1;
    
    return A.x * B.y - B.x * A.y;
}

int counterClockWise(Point O, Point A, Point B){
    Point OA = {A.x - O.x, A.y - O.y};
    Point OB = {B.x - O.x, B.y - O.y};

    int value = crossProd(OA,OB);
    return crossProd(OA,OB);

}
int squareDistance(Point p1, Point p2){
    return (p1.x-p2.x) * (p1.x - p2.x)  + (p1.y-p2.y) * (p1.y - p2.y);
}
bool polarAngle(Point PI,Point PJ){
    return counterClockWise(P0,PI, PJ) > 0;
    // if(c==0){ // TRUNG NHAU
    //     if(squareDistance(P0, PI) >= squareDistance(P0, PJ)) return 0;
    //     else return 1;
    // }
    // if(c==1){ // CUNG CHIEU 
    //     return 0;       
    // }
    // return 1; // NGUOC CHIEU
}
void input(){
}
bool checkIsInSight(Point A, Point B, Point C, Point D){
    // CHECK C, D CO CUNG PHIA VOI A, B
    Point AB  = {B.x-A.x, B.y- A.y};
    Point AC = {C.x-A.x, C.y-A.y};
    Point AD = {D.x - A.x, D.y - A.y};
    // if (counterClockWise(A,B,C) == 0) return false;
    // if (counterClockWise(A,B,D) == 0) return false;
    if (crossProd(AB,AC)  * crossProd(AB,AD)<=0) return false; // KHAC PHIA 
    return true; // CUNG PHIA
}
bool isInConvexHull(vector<Point> hull, Point t){
    if(!checkIsInSight(hull[0], hull[1], t, hull[hull.size()-1])){
        return false;
    }
    if(!checkIsInSight(hull[0],hull[hull.size()-1],t ,hull[1])){
        return false;
    }
    int  l = 1, r= hull.size()-1;
    while(r> l+1){
        int mid = (l+r)/2;
        // cout << counterClockWise(hull[0], hull[mid], t) << "  " << hull[mid].x  << "   " << hull[mid].y  <<endl;
            
        if(counterClockWise(hull[0], hull[mid], t ) * counterClockWise(hull[0], hull[mid] ,hull[hull.size()-1]) >= 0){ // CUNG CHIEU KIM DONG HO
            l = mid;
        }else
        {
            r = mid;
        }
    }
    // cout << "counterClockWise= " ;
    // cout << counterClockWise(hull[0],t,hull[l]) << endl; 
    // if (counterClockWise(hull[0], t, hull[l]) >=0) return true;
    // cout << "l= " << l << " r=" << r << endl;
    return checkIsInSight(hull[l], hull[r],t , hull[0]);
 
}
int solve(){
    vector<Point> p;
    vector<Point> q;
    vector<Point> ans;
 
    cin >> N;
    for(int i =0;i <N;i++){
        cin >> x >> y;
        p.push_back({x,y});
    }
    cin  >> Q;
    for(int i=0;i<Q;i++){
        cin >> x >>y;
        q.push_back({x,y});
    }
 
    sort(p.begin(),p.end(),comp);
    P0 = p[0];
    sort(p.begin()+1, p.end(), polarAngle);
    // for(int i =0; i <p.size(); i++){
    //     cout << p[i].x << " " << p[i].y<<endl;
    // }
    for(int i =0; i< N;i++){
        if(ans.size() <2 )
        {
            ans.push_back(p[i]);
        }
        else
        {
            while(counterClockWise(ans[ans.size()-2], ans[ans.size()-1], p[i]) <= 0 && ans.size() >=2){ // NEU NO CUNG CHIEU KIM DONG HO
                ans.pop_back();
            }
            ans.push_back(p[i]);
        }
    }
    // for (int i=0; i< ans.size();i++){
    //     cout << ans[i].x << " " << ans[i].y << endl;
    // }

    int res = 0;
    for(int i=0; i< q.size(); i++){
        // cout << "query point: " << q[i].x << " " << q[i].y <<endl;
        if(!isInConvexHull(ans,q[i])) 
        {
            res++;
        }
    }
    return res;
 
}
int main()
{
    cin >> T;
    for(int t=1;t<=T;t++){
        int a = solve();
        cout << "#" << t <<" " <<  a<<endl;
        // break;

    }
 
}