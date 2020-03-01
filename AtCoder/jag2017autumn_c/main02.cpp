// https://atcoder.jp/contests/jag2017autumn/submissions/10394423
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;
/*
uint sieve_interval(const uint a, const uint b){
    const uint b_p1  =b+1;
    const uint b_p1_r=sqrt(b_p1)+0.5;
    const uint ab_p1 =b-a+1;
    
    vector<bool> pTbl   (b_p1_r,  true); pTbl[0]=false; pTbl[1]=false; // prime table
//    vector<bool> pTbl_ab(ab_p1, true);                               // prime table
    
    vector<uint> vNum(ab_p1); for(uint i=0; i<vNum.size(); ++i){ vNum[i]=a+i; }
    vector<uint> vCnt(ab_p1, 0);
    
    for(uint ti=2; ti<b_p1_r; ++ti){
        if(!pTbl[ti]){ continue; }
        
        for(uint i=ti*2; i<b_p1_r; i+=ti){ pTbl[i]=false; }
        
        uint tmp = ti;
        while(tmp<b_p1){
            for(uint i = tmp * max(2, (a+tmp-1)/tmp); i<b_p1; i+=tmp){
//                pTbl_ab[i-a]=false;
                vNum[i-a] /= ti;
                ++vCnt[i-a];
            }
            tmp *= ti;
        }
    }
    
    uint numPFP=0;
    for(uint i=0; i<vCnt.size(); ++i){
        if(vNum[i]!=1){ ++vCnt[i]; }
        if(pTbl[ vCnt[i] ]){ ++numPFP; }
    }
    return numPFP;
}
//*/

pair<vector<bool>, vector<uint>> sieve(const uint n){
    const uint n_p1 = n+1;
    vector<bool> pTbl(n_p1, true); pTbl[0]=false; pTbl[1]=false; // prime table
    vector<uint> vPrime;
    for(uint ti=2; ti<n_p1; ++ti){
        if(!pTbl[ti]){ continue; }
        vPrime.push_back( ti );
        for(uint i=ti*2; i<n_p1; i+=ti){ pTbl[i]=false; }
    }
    return {pTbl, vPrime};
}
bool isPrime(const vector<bool>& pTable, uint n){
    if(n>pTable.size()){ return false; }
    return pTable[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uint l, r; cin >> l >> r;
    
    vector<bool> pTbl; vector<uint> vPrime;
    tie(pTbl, vPrime) = sieve( sqrt(r) );
    
    uint n=r-l+1;
//    vector<uint> vNum(n); for(uint i=0; i<n; ++i){ vNum[i]=l+i; }
    vector<uint> vNum(n); for(uint i=l; i<=r; ++i){ vNum[i-l]=i; }
    vector<uint> vCnt(n);
    for(uint pi=0; pi<vPrime.size(); ++pi){
        uint prime = vPrime[pi];
        uint begin = ((l-1)/prime+1) * prime;
//        for(uint i=begin; i-l<n; i+=prime){
        
        for(uint i=begin; i<=r; i+=prime){
            while(vNum[i-l]%prime==0){
                vNum[i-l] /= prime;
                ++vCnt[i-l];
            }
        }
    }
    
    uint numPFP=0;
    for(uint i=0; i<n; ++i){
        if(vNum[i]!=1){ ++vCnt[i]; }
        if(pTbl[ vCnt[i] ]){ ++numPFP; }
    }
//    return numPFP;
    
//    uint numPFP = sieve_interval(l, r);
    cout << numPFP << endl;
    
    return 0;
}
