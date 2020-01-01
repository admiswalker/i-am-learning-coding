// ref: - 蟻本 page. 65 最長増加部分列問題
//      - https://atcoder.jp/contests/abc006/submissions/8344378
// 二分探査 v2

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int dps(const vector<int>& vecA){
    const uint& N = vecA.size();
    vector<int> dp(N, INT_MAX);

    int max_len=1;
    for(uint i=0; i<N; ++i){
        auto pDP = lower_bound(dp.begin(), dp.end(), vecA[i]);
        if(pDP==dp.begin()+max_len){ ++max_len; }
        *pDP = vecA[i];
    }
    
    return max_len;
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
