#include <bits/stdc++.h>
using namespace std;

void dps(const int n, const int m, const int M, const vector<int>& vecA){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // 1 つも選ばない方法は常に 1 通り
    for(int i=0; i<=n; ++i){
        dp[i][0] = 1;
    }
    
    for(int i=0; i<n; ++i){
        for(int j=1; j<=m; ++j){
            if(j-1-vecA[i] >= 0){
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-vecA[i]]) % M;
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
    int n=3;
    int m=3;
    int M=10000;
    
    vector<int> vecA(n);
    vecA[0] = 1;
    vecA[1] = 2;
    vecA[2] = 3;
    
    dps(n, m, M, vecA);
    
    return 0;
}