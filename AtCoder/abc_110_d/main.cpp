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

uint64 nHr(const vector<uint>& vecA, const uint r, const uint64 mod){
    
    const uint& n = vecA.size();
    vector<vector<uint>> dp(n+1, vector<uint>(r+1, 0));
    for(uint i=0; i<=n; ++i){
        dp[i][0] = 1;
    }
    printf("1\n");
    
    for(uint i=0; i<n; ++i){
        for(uint j=1; j<=r; ++j){
            int64 tmp = j-vecA[i]-1ll;
            if(tmp>=0){ dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][tmp]) % mod;
            }   else  { dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]); }
        }
    }
    
    printf("2\n");
    return dp[n][r];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const uint64 mod = 1e9 + 7;
    
    int N, M; cin >> N >> M;
    
    vector<struct fact> vecFact = factor(M);
//    for(uint64 i=0; i<vecFact.size(); ++i){
//        printf(" + %lu^%lu", vecFact[i].prime, vecFact[i].num);
//    }
//    printf("\n");
    
    vector<uint> vecA(vecFact.size());
    for(uint i=0; i<vecFact.size(); ++i){
        printf("%lu  ", vecFact[i].num);
        vecA[i] = vecFact[i].num;
    }
    printf("\n");
    
    cout << nHr(vecA, N, mod) << endl;
    
    return 0;
}
