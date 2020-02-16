#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int costAB(pair<int,int> a, pair<int,int> b){ return min(abs(a.first-b.first), abs(a.second-b.second)); }

vector<uint64> vXY2vCost_u2v(const vector<pair<int,int>>& vXY, const uint u){
    const uint& N = vXY.size();
    vector<uint64> vCost_u2v(N);
    for(uint i=0; i<N; ++i){
        if(i==u){ continue; }
        vCost_u2v[i] = costAB(vXY[i], vXY[u]);
    }
    return vCost_u2v;
}

uint64 solve_prime(const vector<pair<int,int>>& vXY){
    const uint& N = vXY.size();
    vector<bool> vUsed(N, false);
    vector<uint64> vCost_min(N, INT64_MAX); vCost_min[0]=0ull;
    
    uint64 sum_cost=0ull;
    for(;;){
        int minIdx=-1;
        for(uint i=0; i<N; ++i){
            if(!vUsed[i] && (minIdx==-1 || vCost_min[i]<vCost_min[minIdx])){ minIdx=i; }
        }
        if(minIdx==-1){ break; }
        
        vUsed[minIdx] = true;
        sum_cost += vCost_min[minIdx];
        
        for(uint i=0; i<N; ++i){
            vector<uint64> vCost_u2v = vXY2vCost_u2v(vXY, minIdx);
            vCost_min[i] = min(vCost_min[i], vCost_u2v[i]);
        }
    }
    return sum_cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<pair<int,int>> vXY(N);
    for(uint i=0; i<N; ++i){
        uint x, y; cin >> x >> y;
        vXY[i].first  = x;
        vXY[i].second = y;
    }
    
    uint64 ret = solve_prime(vXY);
    cout << ret << endl;
    
    return 0;
}

//        auto vCost_f = passFalse(vCost, vUsed); if(vCost_f.size()==0){ break; }
//        uint minIdx = argmin(vCost_f);

