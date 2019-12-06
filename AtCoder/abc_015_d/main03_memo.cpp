#include <bits/stdc++.h>
using namespace std;

#define dp_m(i, k, w)                           \
    dp[ (K+1)*(W+1)*(i) + (W+1)*(k) + (w) ]
int dps(const vector<int>& vecW, const vector<int>& vecI, const int N, const int K, const int W){
    vector<int> dp((N+1)*(K+1)*(W+1), 0);
    
    for(int i=0; i<N; ++i){
        for(int k=1; k<=K && k<=i; ++k){
            for(int w=0; w<=W; ++w){
                if(w-vecW[i]<0){
                    dp_m(i+1, k, w) = dp_m(i, k, w);
                }else{
                    dp_m(i+1, k, w) = max(dp_m(i, k, w), dp_m(i, k-1, w-vecW[i]) + vecI[i]);
                }
            }
        }
    }
    
    int ans=0;
    for(int k=0; k<=K; ++k){
        for(int w=0; w<=W; ++w){
            ans = max(ans, dp_m(N, k, w));
        }
    }
    return ans;
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
    
    int ans = dps(vecW, vecI, N, K, W);
    cout << ans << endl;
    
    return 0;
}
