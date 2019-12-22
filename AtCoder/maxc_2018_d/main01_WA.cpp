// ref: 蝶本 第 2 版 page. 62 個数制限付き部分和問題

#include <bits/stdc++.h>
using namespace std;

/*
int stdd(int i, int stdVal){ // standardization
//    return (i-stdVal);
    return (i-stdVal);
}//*/

bool dps(const vector<int>& vecA, int M, int L, int X_max){
    const int& N = vecA.size();
    int len_max = L + M*(X_max-1);
    
    vector<int> dp(len_max+1, -1);
    dp[0] = 0;
    
//    int l=0;
    int tf_i=L;
    for(int x=0; x<=X_max; ++x){
        int len = L + M*(x-1);
        
        for(int i=0; i<N; ++i){
            for(int l=0; l<=len; ++l){
//            for(; l<=len; ++l){
                if      (dp[l]>=0                     ){ dp[l] = 1;
                }else if(l<vecA[i] || dp[l-vecA[i]]<=0){ dp[l] = -1;
                }else                                  { dp[l] = dp[l-vecA[i]] - 1; }
            }
        }
        
        for(; tf_i<=len; tf_i+=M){
            if(dp[tf_i]>=0){ return true; }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, L, X;
    cin >> N >> M >> L >> X;
    vector<int> vecA(N);
    for(int i=0; i<N; ++i){ cin >> vecA[i]; }
    
    bool TF = dps(vecA, M, L, X);
    cout << (TF ? "Yes":"No") << endl;
    
    return 0;
}
