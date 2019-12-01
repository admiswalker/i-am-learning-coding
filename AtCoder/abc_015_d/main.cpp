#include <bits/stdc++.h>
using namespace std;

template<typename T>
T maxVal(const vector<T>& rhs){
    T lhs=rhs[0];
    for(uint64_t i=1; i<rhs.size(); ++i){
        if(rhs[i]>lhs){ lhs=rhs[i]; }
    }
    return lhs;
}

struct sAB{
    uint64_t width;
    uint64_t imp;   // importance
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint64_t W;    cin >> W;
    uint64_t N, K; cin >> N >> K;
    vector<struct sAB> vecAB(N);
    for(uint64_t i=0; i<vecAB.size(); ++i){
        cin >> vecAB[i].width >> vecAB[i].imp;
    }
    
    uint64_t numChoices = (uint64_t)1 << vecAB.size();
    
    uint64_t ans=0;
    for(uint64_t n=0; n<numChoices; ++n){
        uint64_t num=0;
        uint64_t width=0;
        uint64_t imp=0;
        for(uint64_t i=0; i<vecAB.size(); ++i){
            if( !(n&((uint64_t)1<<i)) ){ continue; }
            ++num;
            if(num>K){ break; }
            width += vecAB[i].width;
            imp   += vecAB[i].imp;
        }
        if(num>K){ continue; }
        if(width>W){ continue; }
        
        if(ans<imp){ ans=imp; }
    }
    
    cout << ans << endl;
    
    return 0;
}
