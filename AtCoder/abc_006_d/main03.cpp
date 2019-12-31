// ref: 蟻本 page. 63~ 65 最長増加部分列問題

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int dps(const vector<int>& vecA){
    const uint& N = vecA.size();
    
    //*
    vector<int> dp(vecA.size(), INT_MAX); dp[0]=vecA[0];
    
    for(uint i=0; i<N; ++i){
        for(uint j=0; j<=i; ++j){
            if(dp[j] < vecA[i]){
                dp[j] = min(dp[j], vecA[i]);
            }
        }
    }
    //*/
    /*
    for(uint i=0; i<N; ++i){
        for(uint j=0; j<=i; ++j){
            if(i==0 || dp[i-1] < vecA[j]){
                dp[j] = min(dp[i], vecA[j]);
            }
        }
    }//*/
    /*
    vector<int> dp(vecA.size(), INT_MAX);
    for(uint i=1; i<N; ++i){
        for(uint j=0; j<=i; ++j){
            if(dp[i-1] < vecA[j]){
                dp[i] = min(dp[i], vecA[j]);
            }
        }
    }
    //*/
    
    for(uint i=1; i<dp.size(); ++i){
        printf("i: %d, %d\n", i, dp[i]);
        if(dp[i]==INT_MAX){ return i; }
    }
    return 1;
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
