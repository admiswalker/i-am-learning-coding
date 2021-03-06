// https://atcoder.jp/contests/jag2017autumn/submissions/10394423
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

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
    vector<uint> vNum(n); for(uint i=l; i<=r; ++i){ vNum[i-l]=i; }
    vector<uint> vCnt(n);
    for(uint pi=0; pi<vPrime.size(); ++pi){
        uint prime = vPrime[pi];
        uint begin = ((l-1)/prime+1) * prime;
        
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
    cout << numPFP << endl;
    
    return 0;
}
