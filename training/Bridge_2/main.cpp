#include<bits/stdc++.h>
using namespace std;

int m,n;
struct Segment
{
    pair<int,int> p1;
    pair<int, int> p2;
    Segment(pair<int,int> _p1, pair<int,int> _p2){
        p1= _p1;
        p2 = _p2;
    };
    Segment(){}
};
bool comp(pair<int,int> x, pair<int,int> y ){
    if(x.first > y.first) return true;
    if(x.first==y.first && x.second < y.second) return true;
    return false;
}

pair<int,int> L[100];
pair<int, int> R[100];
Segment Sl[105];
Segment Sr[105];

bool dotProd(pair<int,int> O, pair<int,int> A, pair<int,int> B){
    pair<int,int> AO = make_pair(O.first - A.first, O.second - B.second);
    pair<int,int> BO = make_pair(O.first - B.first, O.second - B.second);

    cout << "O: " << O.first << " " << O.second << " A: " << A.first << " " << A.second << " B: "<<B.first << " " << B.second<<endl;
    // cout << 1LL * OA.first * OB.first + 1LL * OB.second * OA.second << endl;
    if(1LL * AO.first * BO.first + 1LL * BO.second * AO.second >= 0) return true; // CUNG PHIA 
    return false;
}
double crossProd(pair<int,int> O, pair<int,int> A, pair<int,int> B){
    pair<int,int> AO = make_pair(O.first - A.first, O.second - B.second);
    pair<int,int> BO = make_pair(O.first - B.first, O.second - B.second);


    // cout << "Cross Product: "<<  AO.first * BO.first -  AO.second * BO.second <<endl;
    double res =  AO.first * BO.second -  AO.second * BO.first;
    // if(res==0){
    // cout << "Point: " << O.first << " "<< O.second << " " << A.first <<" " << A.second << " " << B.first << " " << B.second << endl;
    // cout << dotProd(A,B,O)<<endl;
    // cout << dotProd(B,A,O)<<endl;
    // }
    return AO.first * BO.second -  AO.second * BO.first;
}
bool isInSegment(pair<int,int> p, Segment AB){
    cout << "dotProd(AB.p2,AB.p1, p)= " << int(dotProd(AB.p2,AB.p1, p)) << endl;
    cout << "dotProd(AB.p1,AB.p2,p)= " << int(dotProd(AB.p1,AB.p2,p))<< endl;
    if(dotProd(AB.p2,AB.p1, p) || dotProd(AB.p1,AB.p2,p)){
        return false;
    };
    return true;
}
double segmentLength(Segment AB){
    pair<int,int> A = AB.p1;
    pair<int,int> B = AB.p2;
    // cout << "length= "<<sqrt((A.first-B.first) * (A.first - B.first) + (A.second - B.second) *(A.second - B.second))<<endl;
    return sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) *(A.second - B.second));
}
double distanceFrom(pair<int,int> p, Segment AB){

    // cout <<"isInsegment: "<<  isInSegment(p,AB) << endl;
    if(isInSegment(p,AB)){
        // cout << "crosProd= " << abs(crossProd(p, AB.p1, AB.p2))<<endl;
        return (abs(crossProd(p, AB.p1, AB.p2)) / segmentLength(AB));
    }else
    {
        return min(segmentLength({p,AB.p1}), segmentLength({p,AB.p2}));
    }
}

double distanceLeftToRight(pair<int,int> p){
    double res = 1e100;
    for(int i=0; i < n+1;i++){
        res = min(res, distanceFrom(p, Sr[i]));
    }
    return res;
}
double distanceRightToLeft(pair<int,int> p){
    double res = 1e100;
    for(int i=0; i < m+1;i++){
        res = min(res, distanceFrom(p, Sl[i]));
    }
    return res;
}

int main(){
    cin  >> m;
    int x,y ;
    for(int i =0;i<m; i++){
        cin >> x >> y;
        L[i] = make_pair(x,y);
        // cout << L[i].first << " "<< L[i].second << endl;
    }
    // cout << " ====================================" <<endl;
    cin  >> n;
    for(int i =0;i<n;i++){
        cin >> x >> y;
        R[i] = make_pair(x,y);
        // cout << R[i].first << " " << R[i].second << endl;
    }
    for(int i=0;i<m+1; i++){
        if(i==0){
            Sl[i] = {make_pair( L[i].first,-100000), L[i]};
        }
        else
        {
            if(i==m){
                Sl[i] = {L[i-1], make_pair(L[i-1].first, 100000)};
            }
            else
            {
                Sl[i] = {L[i-1], L[i]};
            }
        }
        
        // cout << Sl[i].p1.first << " " << Sl[i].p1.second << " " << Sl[i].p2.first << " " << Sl[i].p2.second << endl;
    }
    // cout << "=============="<<endl;
    for(int i=0;i<n+1; i++){
        if(i==0){
            Sr[i] = {make_pair( R[i].first,-100000), R[i]};
        }
        else
        {
            if(i==n){
                Sr[i] = {R[i-1], make_pair(R[i-1].first, 100000)};
            }
            else
            {
                Sr[i] = {R[i-1], R[i]};
            }
        }
        
        // cout << Sr[i].p1.first << " " << Sr[i].p1.second << " " << Sr[i].p2.first << " " << Sr[i].p2.second << endl;
    }

    // for(int i=0;i<n-1; i++){
    //     Sr[i] = {R[i], R[i+1]};
    //     cout << Sr[i].p1.first << " " << Sr[i].p1.second << " " << Sr[i].p2.first << " " << Sr[i].p2.second << endl;

    // }
    // for(int i=0; i < n+1;i++){
    //     cout << Sr[i].p1.first << " " << Sr[i].p1.second << " " << Sr[i].p2.first << " "<< Sr[i].p2.second << endl;
    // }
    // cout << "================"<<endl;
    // for(int i=0; i < m+1;i++){
    //     cout << Sl[i].p1.first << " " << Sl[i].p1.second << " " << Sl[i].p2.first << " "<< Sl[i].p2.second << endl;
    // }

    double min_distance = 1e100;
    for(int i =0; i<m;i++){
        min_distance = min(min_distance, distanceLeftToRight(L[i]));
    }
    for(int i=0; i <n;i++){
        min_distance = min(min_distance,distanceRightToLeft(R[i]));
    }
    cout << min_distance << endl;
}