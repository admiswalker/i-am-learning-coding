#include <bits/stdc++.h>
using namespace std;

struct VW{
    int64_t v;
    int64_t w;
};

#define dp_m(i, j)                              \
    dp[(W+1)*(i) + (j)]
int64_t dps(const vector<struct VW>& vecVW, const int64_t N, const int64_t W){
    vector<int64_t> dp((N+1)*(W+1), 0);
    
    for(int64_t i=0; i<N; ++i){
        for(int64_t w=0; w<=W; ++w){
            int64_t w_minusW = w - vecVW[i].w;
            if(w_minusW<0){ dp_m(i+1, w) = dp_m(i, w);
            }    else     { dp_m(i+1, w) = max(dp_m(i, w), dp_m(i, w_minusW)+vecVW[i].v);
            }
        }
    }
    
    return dp_m(N, W);
}
#undef dp_m

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<struct VW> vecVW(N);
    for(unsigned int i=0; i<vecVW.size(); ++i){ cin >> vecVW[i].v >> vecVW[i].w; }
    
    cout << dps(vecVW, N, W) << endl;
    
    return 0;
}
