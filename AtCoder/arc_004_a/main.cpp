#include <bits/stdc++.h>
using namespace std;

struct XY{
    double x;
    double y;
};

double pow2(const double& rhs){ return rhs*rhs; }

double distance(const struct XY& lhs, const struct XY& rhs){
    return sqrt( pow2(abs(lhs.x-rhs.x)) + pow2(abs(lhs.y-rhs.y)) );
}

template <typename T>
T max(const vector<T>& v){
    T max=v[0];
    for(int i=1; i<v.size(); ++i){
        if(v[i]>max){ max=v[i]; }
    }
    return max;
}

int main(){
    int N; cin >> N;
    vector<struct XY> vecXY(N);
    for(int i=0; i<vecXY.size(); ++i){
        cin >> vecXY[i].x;
        cin >> vecXY[i].y;
    }
    
    vector<double> vecD;
    for(int src=0; src<vecXY.size(); ++src){
        for(int dst=src+1; dst<vecXY.size(); ++dst){
            vecD.push_back( distance(vecXY[src], vecXY[dst]) );
        }
    }
    
    cout << max(vecD);
    
    return 0;
}
