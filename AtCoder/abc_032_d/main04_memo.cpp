#include <bits/stdc++.h>
using namespace std;

int64_t sum(const vector<int>& vecRhs){
    int64_t sum=0ll;
    for(unsigned int i=0; i<vecRhs.size(); ++i){
        sum += vecRhs[i];
    }
    return sum;
}

#define dp_m(i, j)                              \
    dp[(sumV+1)*(i) + (j)]
int64_t dps(const vector<int>& vecV, const vector<int>& vecW, const uint64_t N, const int64_t W){
    int64_t sumV = sum(vecV);
    
    vector<int64_t> dp((N+1)*(sumV+1), 0);
    dp_m(0, 0) = 0ll;
    for(int i=1; i<=sumV; ++i){ dp_m(0, i)=LLONG_MAX/2; }
    
    for(uint64_t i=0; i<N; ++i){
        for(int64_t v=0; v<=sumV; ++v){
            int64_t cal = v - vecV[i];
            if(cal<0){ dp_m(i+1, v) = dp_m(i, v);
            }  else  { dp_m(i+1, v) = min(dp_m(i, v), dp_m(i, cal)+vecW[i]);
            }
        }
    }
    
    int64_t ans=0ll;
    for(int64_t v=0; v<=sumV; ++v){
        if(dp_m(N, v)<=W){ ans = v; }
    }
    return ans;
}
#undef dp_m

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<int> vecV(N);
    vector<int> vecW(N);
    for(int i=0; i<N; ++i){ cin >> vecV[i] >> vecW[i]; }
    
    cout << dps(vecV, vecW, N, W) << endl;
    
    return 0;
}
