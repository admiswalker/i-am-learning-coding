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

uint64 factorial(const uint64 n){
    uint64 ret=1ull;
    for(uint64 i=2ull; i!=(n+1ull); ++i){ ret*=i; }
    return ret;
}
uint64 comb_base(const uint64 n, const uint64 r){
    uint64 ret=1ull;
    for(uint64 i=n; i!=n-r; --i){ ret*=i; }
    return ret / factorial(r);
}
uint64 comb(const uint64 n, const uint64 r){
    if      (n==r ){ return 1ull;
    }else if(n-r<r){ return comb_base(n, n-r);
    }else          { return comb_base(n, r  ); }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const uint64 mod = 1e9 + 7;
    
    int N, M; cin >> N >> M;
    
    vector<struct fact> vecFact = factor(M);
    vector<uint> vecA(vecFact.size());
    for(uint i=0; i<vecFact.size(); ++i){
        vecA[i] = vecFact[i].num;
    }
    
    uint64 ans=1ull;
    for(uint i=0; i<vecA.size(); ++i){
        ans *= comb(vecA[i]+N-1, N-1);
        ans %= mod;
    }
    
    cout << ans << endl;
    return 0;
}
