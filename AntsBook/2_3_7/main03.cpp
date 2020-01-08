#include <bits/stdc++.h>
using namespace std;

void dps(const int n, const int m, const int mod){
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for(int i=1; i<=m; ++i){
        for(int j=0; j<=n; ++j){
            if(j-i>=0){
                dp[j] += dp[j-i];
                dp[j] %= mod;
            }else{
                dp[j]  = dp[i-1];
                dp[j] %= mod;
            }
        }
    }
    printf("%d\n", dp[m]);
}

int main(){
    int n=4;
    int m=3;
    int mod=10000;
    
    dps(n, m, mod);
    
    return 0;
}

/*
4
3
10000
*/
