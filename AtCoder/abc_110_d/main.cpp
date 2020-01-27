// ref: https://atcoder.jp/contests/abc110/submissions/3251714

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint64  divNum(uint64& target, const uint64 divisor){
    uint64 num  =0ull;
    for(;;){
        uint64 div = target / divisor;
        uint64 mod = target - divisor * div;
        if(mod!=0ull){ break; }
        target = div;
        ++num;
    }
    return num;
}

tuple<vector<uint64>,vector<uint64>> factor(uint64 target){
    vector<uint64> vecPrime;
    vector<uint64> vecNum;
    
    uint64 num2 = divNum(target, 2ull);
    if(num2!=0ull){
        vecPrime.push_back(2ull);
        vecNum.push_back(num2);
    }
    
    for(uint64 divisor=3; divisor<=target; divisor+=2){
        if(target==1){ break; }
        
        uint64 num = divNum(target, divisor);
        if(num==0ull){ continue; }
        
        vecPrime.push_back(divisor);
        vecNum.push_back(num);
    }
    return tie(vecPrime, vecNum);
}

uint64 pow_mod(uint64 base, uint64 exp, const uint64 mod){
    uint64 ret=1ull;
    for(; exp>0ull; exp>>=1ull){
        if(exp & 1){
            ret = ret*base;
            ret %= mod;
        }
        base = base*base;
        base %= mod;
    }
    return ret;
}
uint64 comb_mod(uint64 n, uint64 r, const uint64 mod){
    if(n==r || n==0ull || r==0ull){ return 1ull; }
    
    uint64 p=1ull, q=1ull;
    r = min(r,n-r);
    for(uint64 i=1ull; i<=r; ++i){
        p *= n; --n;
        p %= mod;
        
        q *= i;
        q %= mod;
    }
    return (p*pow_mod(q,mod-2,mod)) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const uint64 mod = 1e9 + 7;
    
    uint64 N, M; cin >> N >> M;
    
    vector<uint64> vecPrime, vecNum;
    tie(vecPrime, vecNum) = factor(M);
    
    uint64 ans=1ull;
    for(uint i=0; i<vecNum.size(); ++i){
        ans *= comb_mod(vecNum[i]+N-1ull, N-1ull, mod);
        ans %= mod;
    }
    
    cout << ans << endl;
    return 0;
}
