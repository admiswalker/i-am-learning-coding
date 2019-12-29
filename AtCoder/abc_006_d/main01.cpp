// ref: 蟻本 page. 63~ 65 最長増加部分列問題

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int dps(const vector<int>& vecA){
    const uint& N = vecA.size();
    vector<int> dp(vecA.size(), 1);
    int len_max=0;
    
    for(uint end=0; end<N; ++end){
        for(uint i=0; i<end; ++i){
            if(vecA[i] < vecA[end]){
                dp[end] = max(dp[end], dp[i]+1);
            }
        }
        len_max = max(len_max, dp[end]);
    }
    return len_max;
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
