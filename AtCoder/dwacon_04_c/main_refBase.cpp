// ref of base: https://atcoder.jp/contests/dwacon2018-prelims/submissions/3318731

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef int64_t int64;


template<typename T>
T sum(const vector<T>& rhs){
    T lhs = rhs[0];
    for(unsigned int i=1; i<rhs.size(); ++i){ lhs+=rhs[i]; }
    return lhs;
}

vector<int> countVecElem(const vector<int>& vecIn){
    const int& N = vecIn.size();
    vector<int> vecCount(N);
    
    int ct=2;
    vecCount[0]=1;
    for(int i=1; i<N; i++){
        if(vecIn[i-1]!=vecIn[i]){ ct=1; }
        vecCount[i] = ct;
        ct++;
    }
    return vecCount;
}
/*
int64 dps(const vector<>){
    vector<int64> dpa(sum_b+1); dpa[0]=1;
    for(int i=0; i<N; i++){
        for(int j=vecC_a[i]; j<=sum_b; j++){
            dpa[j] += dpa[j-vecC_a[i]];
            dpa[j] %= MOD;
        }
    }
    return dpa[sum_x];
}
//*/

int main(){
    const int64 MOD=1e9+7;
    int N, M;
    cin >> N >> M;
    
    vector<int> vecA(N);
    vector<int> vecB(M);
    for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }
    for(uint i=0; i<vecB.size(); ++i){ cin >> vecB[i]; }
    
    int sum_a = sum(vecA);
    vector<int> vecC_a = countVecElem(vecA);
    
    int sum_b = sum(vecB);
    vector<int> vecC_b = countVecElem(vecB);
    
    vector<int64> dpa(sum_b+1); dpa[0]=1;
    for(int i=0; i<N; i++){
        for(int j=vecC_a[i]; j<=sum_b; j++){
            dpa[j] += dpa[j-vecC_a[i]];
            dpa[j] %= MOD;
        }
    }
    
    vector<int64> dpb(sum_a+1);
    dpb[0]=1;
    for(int i=0; i<M; i++){
        for(int j=vecC_b[i]; j<=sum_a; j++){
            dpb[j] += dpb[j-vecC_b[i]];
            dpb[j] %= MOD;
        }
    }
    cout<<dpa[sum_b]*dpb[sum_a]%MOD<<endl;
    return 0;
}
