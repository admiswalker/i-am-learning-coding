#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define MAX_M 1000

int n, m, M;
int a[MAX_N];

int dp[MAX_N + 1][MAX_M + 1]; // DP テーブル

void solver(){
    // 1 つも選ばない方法は常に 1 通り
    for(int i=0; i<=n; ++i){
        dp[i][0] = 1;
    }
    
    for(int i=0; i<n; ++i){
        for(int j=1; j<=m; ++j){
            if(j-1-a[i] >= 0){
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]] + M) % M;
            }else{
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    n=3;
    m=3;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    M=10000;
    
    solver();
    
    return 0;
}
