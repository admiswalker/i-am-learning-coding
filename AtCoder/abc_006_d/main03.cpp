// ref: 蟻本 page. 63~ 65 最長増加部分列問題
// type 2

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int dps(const vector<int>& vecA){
    const uint& N = vecA.size();
    
    vector<int> dp(vecA.size(), INT_MAX);
    
    for(uint n=0; n<N; ++n){
        for(uint t=0; t<=n; ++t){
            if(t==0 || dp[t-1] < vecA[n]){
                dp[t] = min(dp[t], vecA[n]);
            }
        }
    }
    
    for(uint i=1; i<dp.size(); ++i){
        if(dp[i]==INT_MAX){ return i; }
    }
    return dp.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vecA(N);
    for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }
    
    int maxLen = dps(vecA);
    cout << (N-maxLen) << endl;
    
    return 0;
}
