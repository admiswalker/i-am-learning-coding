#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint max(const uint lhs, const uint rhs){ return (lhs>rhs) ? lhs : rhs; }
/*
uint sieve_num(uint l, uint r){
    uint p=0;
    uint n = sqrt(r) + 1;
    vector<bool> pTable(n, true); pTable[0]=false; pTable[1]=false;
    for(uint ti=0; ti<n; ++ti){
        if(!pTable[ti]){ continue; }
        ++p;
        for(uint i=ti*2; i<r; i+=ti){ pTable[i]=false; }
//        for(uint i=max(2, (ti+l-1)/ti)*ti; i<n; ++i){ pTable[i]=false; }
    }
    return p;
}
//*/

uint sieve(const uint n){
    uint p=0;
//    uint rN = sqrt(n);
    vector<bool> pTable(n+1, true); pTable[0]=false; pTable[1]=false;
    for(uint ti=2; ti<=n; ++ti){
        if(!pTable[ti]){ continue; }
        ++p;
        for(uint i=ti*2; i<n+1; i+=ti){ pTable[i]=false; }
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint r; cin >>  r;
//    uint l, r; cin >> l >> r;
//    uint ret = sieve_num(l, r);
//    uint ret = sieve(l, r);
    uint ret = sieve(r);
    cout << ret << endl;
    
    return 0;
}
