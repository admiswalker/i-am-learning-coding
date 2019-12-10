#include <bits/stdc++.h>
using namespace std;

#define MAX_N 30
#define MAX_V 20

int dp[MAX_N+1][MAX_N*MAX_V+1];
int dps(const vector<int>& vecV, const vector<int>& vecW, int N, int W){
//    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, LLONG_MAX);
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, 1000);
    dp[0][0] = 0;
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<=MAX_N*MAX_V; ++j){
            if(j<vecV[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = min(dp[i][j], dp[i][j-vecV[i]] + vecW[i]);
            }
        }
    }
    
    int res=0;
    for(int i=0; i<=MAX_N*MAX_V; ++i){
//        printf("dp[N][i]: %d\n", dp[N][i]);
        if(dp[N][i]<=W){ res=i; }
    }
    
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    printf("N: %d\n", N);
    printf("W: %d\n", W);
    vector<int> vecV(N);
    vector<int> vecW(N);
    for(int i=0; i<N; ++i){ cin >> vecV[i] >> vecW[i]; }
//    for(int i=0; i<N; ++i){ printf("%d ", vecV[i]); } printf("\n");
//    for(int i=0; i<N; ++i){ printf("%d ", vecW[i]); } printf("\n");
    
    cout << dps(vecV, vecW, N, W) << endl;
    
    return 0;
}

/*
4 5
3 2
2 1
4 3
2 2
*/
