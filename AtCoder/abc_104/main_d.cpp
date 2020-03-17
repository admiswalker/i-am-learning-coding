// https://img.atcoder.jp/abc104/editorial.pdf
// https://atcoder.jp/contests/abc104/submissions/2955456

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int64 MOD = 1000000007;
    string s; cin >> s;
    int N = s.size();
    
    vector<vector<int64>> dp(N+1, vector<int64>(4LL));
    
    for(int i=N; i>=0; --i){
        for(int j=3; j>=0; --j){
            if(i==N){
                dp[i][j] = (j<3 ? 0LL:1LL);
            }else{
                dp[i][j] = dp[i+1][j] * (s[i]=='?' ? 3LL:1LL);
                if(j<3 && (s[i]=='?' || s[i]=="ABC"[j])){
                    dp[i][j] += dp[i+1][j+1];
                }
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
    
    return 0;
}
