#include <bits/stdc++.h>
using namespace std;

int dps(const vector<int>& vecW, const vector<int>& vecI, const int N, const int K, int i, int k, int w)
{
    // k: remaining width
    // w: remaining width
    
    int res;
    int n = vecW.size();
    if(i>=N || k>=K){
        res = 0;
    }else if(w-vecW[i]<0){
        res = dps(vecW, vecI, N, K, i+1, k, w);
    }else{
        res = max( dps(vecW, vecI, N, K, i+1, k, w), dps(vecW, vecI, N, K, i+1, k+1, w-vecW[i]) + vecI[i] );
    }
    return res;
}

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
    
    int ans = dps(vecW, vecI, N, K, 0, 0, W);
    cout << ans << endl;
    
    return 0;
}
