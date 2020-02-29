#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint max(const uint lhs, const uint rhs){ return (lhs>rhs) ? lhs : rhs; }
uint countTrue(const vector<bool>& vRhs){
    uint num=0; for(uint i=0; i<vRhs.size(); ++i){ if(vRhs[i]){++num;} } return num;
}

uint sieve_num_lr(const uint l, const uint r){
    const uint n=r-l+1;
    const uint rR = sqrt(r)+0.5;
    vector<bool> pTable   (rR+1, true); pTable[0]=false; pTable[1]=false;
    vector<bool> pTable_lr( n+1, true);
    for(uint ti=2; ti<=rR; ++ti){
        if(!pTable[ti]){ continue; }
        for(uint i=ti*2; i<rR+1; i+=ti){ pTable[i]=false; }
        for(uint i=((l-1)/ti + 1)*ti; i<r+1; i+=ti){ pTable_lr[i-l]=false; }
    }
    return countTrue(pTable_lr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint l, r; cin >> l >> r;
    uint ret = sieve_num_lr(l, r);
    cout << ret << endl;
    
    return 0;
}
