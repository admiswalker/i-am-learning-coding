// ref: https://atcoder.jp/contests/abc110/submissions/3251714

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct fact{
private:
public:
    fact(){ prime=0ull; num=0ull; }
    fact(const uint64 p_in, const uint64 n_in){ prime=p_in; num=n_in; }
    ~fact(){}
    
    uint64 prime;
    uint64 num;
};

struct fact divNum(uint64& target, const uint64 divisor){
    struct fact fa(divisor, 0ull);
    for(;;){
        uint64 div = target / divisor;
        uint64 mod = target - divisor * div;
        if(mod!=0ull){ break; }
        target = div;
        ++fa.num;
    }
    return fa;
}

vector<struct fact> factor(uint64 target){
    vector<struct fact> vecFact;
    
    struct fact fa2 = divNum(target, 2ull);
    if(fa2.num!=0ull){ vecFact.push_back(fa2); }
    
    for(uint64 divisor=3; divisor<=target; divisor+=2){
        if(target==1){ break; }
        
        struct fact fa = divNum(target, divisor);
        if(fa.num==0ull){ continue; }
        
        vecFact.push_back(fa);
    }
    return vecFact;
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
    
    vector<struct fact> vecFact = factor(M);
    vector<uint64> vecA(vecFact.size());
    for(uint i=0; i<vecFact.size(); ++i){
        vecA[i] = vecFact[i].num;
    }
    
    uint64 ans=1ull;
    for(uint i=0; i<vecA.size(); ++i){
        ans *= comb_mod((uint64)vecA[i]+(uint64)N-1ull, (uint64)N-1ull, mod);
        ans %= mod;
    }
    
    cout << ans << endl;
    return 0;
}
