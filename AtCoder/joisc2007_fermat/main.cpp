// https://atcoder.jp/contests/joisc2007/submissions/10364807
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint64 pow_mod(uint64 x, uint64 n, const uint64 mod){
    uint64 res = 1ull;
    while(n > 0){
        if(n & 1){ res = res * x % mod; }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint p, n; cin >> p >> n;
    
    vector<uint64> vXYZ(p);
    for(uint i=0; i<p; ++i){ vXYZ[i] = pow_mod(i, n, p); }
    
    unordered_map<uint64, uint64> hashT(p);
    for(uint i=0; i<p; ++i){
        if(hashT.find(vXYZ[i])==hashT.end()){
            hashT[vXYZ[i]] = 1;
        }else{
            ++hashT[vXYZ[i]];
        }
    }
    
    uint64 num=0;
    for(uint x=0; x<p; ++x){
        for(uint y=0; y<p; ++y){
            uint64 tmp = (vXYZ[x] + vXYZ[y]) % p;
            if(hashT.find(tmp)==hashT.end()){ continue; }
            num += hashT[tmp];
        }
    }
    cout << num << endl;
    
    return 0;
}
