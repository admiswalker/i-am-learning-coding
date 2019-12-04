#include <bits/stdc++.h>
using namespace std;

#define dp_m(i, k, w)                           \
    dp[ (K+1)*(W+1)*i + (W+1)*k + w ]

int dps(vector<int>& dp, const vector<int>& vecW, const vector<int>& vecI, const int N, const int K, const int W, int i, int k, int w)
{
    // k: remaining width
    // w: remaining width
    if( dp_m(i, k, w)>=0 ){ return dp_m(i, k, w); }
    
    int res;
    if(i>=N || k>=K){
        res = 0;
    }else if(w-vecW[i]<0){
        res = dps(dp,vecW,vecI,N,K,W, i+1, k, w);
    }else{
        res = max( dps(dp,vecW,vecI,N,K,W, i+1, k, w), dps(dp,vecW,vecI,N,K,W, i+1, k+1, w-vecW[i]) + vecI[i] );
    }
    
    dp_m(i, k, w) = res;
    return res;
}
#undef dp_m

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int W;    cin >> W;
    int N, K; cin >> N >> K;
    vector<int> vecW(N); // width
    vector<int> vecI(N); // importance
    for(int i=0; i<N; ++i){
        cin >> vecW[i] >> vecI[i];
    }
    
    vector<int> dp((N+1)*(K+1)*(W+1), -1);
    int ans = dps(dp, vecW, vecI, N, K, W, 0, 0, W);
    cout << ans << endl;
    
    return 0;
}
