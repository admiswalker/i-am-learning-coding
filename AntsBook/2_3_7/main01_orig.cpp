// ref: ants book page. 66


#include <bits/stdc++.h>
using namespace std;

#define MAX_M 1000
#define MAX_N 1000

int n, m, M;

int dp[MAX_M+1][MAX_N+1];

void solver(){
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >= 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
            } else {
                dp[i][j] = dp[i - 1][j] % M;
            }
        }
    }
    printf("%d\n", dp[m][n]);
}

int main(){
    n=4;
    m=3;
    M=10000;
    
    solver();
    
    return 0;
}

/*
4
3
10000
*/
