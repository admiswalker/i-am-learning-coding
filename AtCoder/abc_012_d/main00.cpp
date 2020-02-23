#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

void warshallFloyd(vector<vector<int64>>& mCost){
    const uint& N=mCost.size();
    for(uint i=0; i<N; ++i){
        for(uint p=0; p<N; ++p){
            for(uint q=0; q<N; ++q){
                if(mCost[p][i]==INT64_MAX || mCost[i][q]==INT64_MAX){ continue; }
                mCost[p][q] = min(mCost[p][q], mCost[p][i] + mCost[i][q]);
            }
        }
    }
}

template<typename T>
T min(const vector<T>& vRhs){
    T ret = vRhs[0];
    for(uint i=1; i<vRhs.size(); ++i){ if(vRhs[i]<ret){ ret=vRhs[i]; } }
    return ret;
}
template<typename T>
T max(const vector<T>& vRhs){
    T ret = vRhs[0];
    for(uint i=1; i<vRhs.size(); ++i){ if(vRhs[i]>ret){ ret=vRhs[i]; } }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    vector<vector<int64>> mCost(N, vector<int64>(N, INT64_MAX)); // mat cost
    for(uint i=0; i<N; ++i){ mCost[i][i] = 0ll; }
    
    for(uint i=0; i<M; ++i){
        uint a, b, c; cin >> a >> b >> c; --a; --b;
        mCost[a][b] = c;
        mCost[b][a] = c;
    }
    
    warshallFloyd(mCost);
    
    vector<int64> vCost_max(N);
    for(uint i=0; i<N; ++i){
        vCost_max[i] = max(mCost[i]);
    }
    cout << min(vCost_max) << endl;
    
    return 0;
}
