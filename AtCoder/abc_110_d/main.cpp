#include <bits/stdc++.h>
using namespace std;
typedef uint64_t uint64;


uint64 nextMul(const vector<char>& tbl, uint64 mul){
    for(uint64 i=mul+1; i<tbl.size(); ++i){
        if(tbl[i]==0){ return i; }
    }
    return INT64_MAX;
}

vector<uint64> prime(uint64 limit){
    vector<char> tbl(limit, 0);
    
    tbl[0] = 1;
    tbl[1] = 1;
    for(uint64 mul=2; mul<limit; ){
        for(uint64 i=2; mul*i<limit; ++i){
            tbl[mul * i] = 1;
//            printf("%lu  ", mul * i);
        }
        mul = nextMul(tbl, mul);
    }
    
    vector<uint64> lhs;
    for(uint64 i=2; i<limit; ++i){
        if(tbl[i]==0){ lhs.push_back(i); }
    }
    return lhs;
}
/*
vector<pari<uint64,uint64>> factor(const uint64 rhs){
    vector<uint64> vecTable;
    vector<pari<uint64,uint64>> ret;
    for(){
        ;
    }
    return ;
}
//*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const uint64 mod = 1e9 + 7;
    
    int N, M;
    cin >> N >> M;
    
//    vector<uint64> vecPrime = factor(M/2+1);
    vector<uint64> vecPrime = prime(M/2+1);
    for(uint64 i=0; i<vecPrime.size(); ++i){
        printf("%lu  ", vecPrime[i]);
    }
    printf("\n");
    
    return 0;
}
