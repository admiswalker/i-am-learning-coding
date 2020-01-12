// ref of base: ants book page. 66

#include <bits/stdc++.h>
using namespace std;

void dps(const int n, const int m, const int mod){
    vector<int> dp(m+1, 0); dp[0] = 1;
    
    for(int i=0; i<m; ++i){
        for(int j=i; j<=n; ++j){
            dp[j] += dp[j-i];
            dp[j] %= mod;
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
