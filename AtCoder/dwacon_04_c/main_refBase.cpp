// ref of base: https://atcoder.jp/contests/dwacon2018-prelims/submissions/3318731

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef int64_t int64;

int sum(const vector<int>& rhs){
    int lhs = rhs[0];
    for(unsigned int i=1; i<rhs.size(); ++i){ lhs+=rhs[i]; }
    return lhs;
}

int main(){
    const int64 MOD=1e9+7;
    int N, M;
    cin >> N >> M;
    
    vector<int> vecA(N); //vecA[0]=-1;
    vector<int> vecB(M); //vecB[0]=-1;
    for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }
    for(uint i=0; i<vecB.size(); ++i){ cin >> vecB[i]; }
    
    int cta[101], ctb[101];
//    int sa=0, sb=0;
    int ct;
    
    ct=1;
    int sum_a = sum(vecA);
    for(int i=1; i<N; i++){
//    for(int i=1; i<=N; i++){
//        sum_a += vecA[i];
        if(vecA[i]!=vecA[i-1]) ct=1;
        cta[i]=ct;
        ct++;
    }
    
    ct=1;
    int sum_b = sum(vecB);
    for(int i=1; i<M; i++){
//    for(int i=1; i<=M; i++){
//        sb+=vecB[i];
        if(vecB[i]!=vecB[i-1]) ct=1;
        ctb[i]=ct;
        ct++;
    }
    
    int64 dpa[1001]={}, dpb[1001]={};
    dpa[0]=1, dpb[0]=1;
    for(int i=1; i<=N; i++){
        for(int j=cta[i]; j<=sum_b; j++){
            dpa[j]+=dpa[j-cta[i-1]];
            dpa[j]%=MOD;
        }
    }
    for(int i=1; i<=M; i++){
        for(int j=ctb[i]; j<=sum_a; j++){
            dpb[j]+=dpb[j-ctb[i-1]];
            dpb[j]%=MOD;
        }
    }
    cout<<dpa[sum_b]*dpb[sum_a]%MOD<<endl;
    return 0;
}
