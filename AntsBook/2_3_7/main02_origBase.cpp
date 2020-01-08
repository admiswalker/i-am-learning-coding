// ref: ants book page. 66

#include <bits/stdc++.h>
using namespace std;

void dps(const int n, const int m, const int mod){
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    dp[0][0] = 1;
    for(int i=1; i<=m; ++i){
        for(int j=0; j<=n; ++j){
            if(j-i >= 0){
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % mod;
            }else{
                dp[i][j] = dp[i-1][j] % mod;
            }
        }
    }
    printf("%d\n", dp[m][n]);
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
