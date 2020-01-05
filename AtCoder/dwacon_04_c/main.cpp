#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

void dps(const vector<int>& vecA){
    const int& N = vecA.size();
    vector<vector<int>> dp(N+1);
    for(int i=0; i<dp.size(); ++i){ dp[i].resize(N); }
    
    for(int i=0; i<; ++i){
        for(int j=0; j<; ++j){
            
        }
    }
    
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> vecA(N); for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }
    vector<int> vecB(M); for(uint i=0; i<vecB.size(); ++i){ cin >> vecB[i]; }
    
    int ans = dps(vecA) * dps(vecB);
    cout << ans << endl;
    
    return 0;
}
