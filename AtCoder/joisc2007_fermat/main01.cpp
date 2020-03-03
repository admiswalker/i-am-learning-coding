//ref: https://atcoder.jp/contests/joisc2007/submissions/10364807
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
    
    vector<uint> vCnt(p, 0);
    for(uint i=0; i<p; ++i){ ++vCnt[pow_mod(i, n, p)]; }
    
    uint64 num=0ull;
    for(uint x=0; x<p; ++x){
        if(vCnt[x]==0){ continue; }
        for(uint y=0; y<x; ++y){
//            uint z = (x + y) % p;
            uint z = x + y; if(z>=p){ z-=p; }
            num += vCnt[x] * vCnt[y] * vCnt[z];
        }
    }
    num *= 2;
    
    for(uint xy=0; xy<p; ++xy){
//        uint z = (xy + xy)%p;
        uint z = 2*xy; if(z>=p){ z-=p; }
        num += vCnt[xy] * vCnt[xy] * vCnt[z];
    }
    
    cout << num << endl;
    
    return 0;
}
