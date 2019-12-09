#include <bits/stdc++.h>
using namespace std;

int64_t sum(const vector<struct VW>& vecRhs){
    int64_t sum=0ll;
    for(int i=0; i<vecRhs.size(); ++i){
        sum += vecRhs[i];
    }
    return sum;
}

#define dp_m(i, j)                              \
    dp[(W+1ull)*(i) + (j)]
int64_t dps(const vector<struct VW>& vecV, const vector<struct VW>& vecW, const uint64_t N, const int64_t W){
    int64_t sumV = sum(vecV);
    
    vector<int64_t> dp((N+1)*(sumV+1), LLONG_MAX);
    
    for(uint64_t i=0; i<N; ++i){
        for(int64_t v=0; v<=sumV; ++v){
            int64_t cal = v - vecV[i];
            if(cal<0){ dp_m((i+1), v) = dp_m(i, v);
            }  else  { dp_m((i+1), v) = max(dp_m(i, v), dp_m(i, cal)+vecV[i]);
            }
        }
    }
    
    return dp_m(N&1ull, W);
}
#undef dp_m

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<int> vecV(N);
    vector<int> vecW(N);
    for(unsigned int i=0; i<N; ++i){ cin >> vecV[i] >> vecW[i]; }
    
    cout << dps(vecV, vecW, N, W) << endl;
    
    return 0;
}
