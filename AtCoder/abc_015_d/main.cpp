#include <bits/stdc++.h>
using namespace std;

template<typename T>
int64_t maxVal(const vector<T>& rhs){
    T lhs=rhs[0];
    for(int64_t i=1; i<rhs.size(); ++i){
        if(rhs[i]>lhs){ lhs=rhs[i]; }
    }
    return lhs;
}

struct sAB{
    int64_t width;
    int64_t imp;   // importance
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64_t W;    cin >> W;
    int64_t N, K; cin >> N >> K;
    vector<struct sAB> vecAB(N);
    for(int64_t i=0; i<vecAB.size(); ++i){
        cin >> vecAB[i].width >> vecAB[i].imp;
    }
    
    int64_t numChoices = 1 << vecAB.size();
    
    vector<int64_t> vecImp;
    int64_t impBuf=0;
    for(int64_t n=0; n<numChoices; ++n){
        int64_t num=0;
        int64_t width=0;
        int64_t imp=0;
        for(int64_t i=0; i<vecAB.size(); ++i){
            if( !(n&(1<<i)) ){ continue; }
            ++num;
            width += vecAB[i].width;
            imp   += vecAB[i].imp;
        }
        if(num>K){ continue; }
        if(width>W){ continue; }
        vecImp.emplace_back(imp);
    }
    
    cout << maxVal(vecImp) << endl;
    
    return 0;
}
