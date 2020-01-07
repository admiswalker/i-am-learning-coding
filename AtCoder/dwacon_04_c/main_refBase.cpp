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

int64 dps(const vector<int>& vecC, int len, int mod){
    vector<int64> dp(len+1); dp[0]=1;
    for(int i=0; i<N; i++){
        for(int j=vecC[i]; j<=len; j++){
            dp[j] += dpa[j-vecC[i]];
            dp[j] %= MOD;
        }
    }
    return ;
}

int main(){
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
    
    const int64 MOD=1e9+7;
    int64 cmbA = dps(vecC_a, sum_b, mod);
    int64 cmbA = dps(vecC_b, sum_a, mod);
    
    cout << cmbA*cmbB << endl;
    
    return 0;
}
