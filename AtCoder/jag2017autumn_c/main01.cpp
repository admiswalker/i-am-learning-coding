// ref: https://atcoder.jp/contests/jag2017autumn/submissions/3144664
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint max(const uint lhs, const uint rhs){ return lhs>rhs ? lhs:rhs; }

uint sieve_interval(const uint a, const uint b){
    const uint ab_p1 = b-a+1;
    vector<bool> pTbl(b, true); pTbl[0]=false; pTbl[1]=false; // prime table
    vector<uint> vNum(ab_p1); for(uint i=0; i<vNum.size(); ++i){ vNum[i]=a+i; }
    vector<uint> vCnt(ab_p1, 0);
    
    for(uint ti=2; ti*ti<b; ++ti){
        if(!pTbl[ti]){ continue; }
        
        for(uint i=ti*2; i*i<b; i+=ti){ pTbl[i]=false; }
        
        uint ti_tmp = ti;
        while(ti_tmp<b){
            for(uint i=ti_tmp*((a-1)/ti_tmp+1); i<b; i+=ti_tmp){
//            for(uint i=ti_tmp * max((uint)2, (a+ti_tmp-1)/ti_tmp); i<b; i+=ti_tmp){
                vNum[i-a] /= ti;
                ++vCnt[i-a];
            }
            ti_tmp *= ti;
        }
    }
    
    uint numPFP=0;
    for(uint i=0; i<vCnt.size(); ++i){
        if(vNum[i]!=1){ ++vCnt[i]; }
        if(pTbl[ vCnt[i] ]){ ++numPFP; }
    }
    return numPFP;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint l, r; cin >> l >> r;
    uint numPFP = sieve_interval(l, r+1);
    cout << numPFP << endl;
    
    return 0;
}
