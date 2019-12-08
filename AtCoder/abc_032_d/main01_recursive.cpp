#include <bits/stdc++.h>
using namespace std;

struct VW{
    int64_t v;
    int64_t w;
};

int64_t dps(const vector<struct VW>& vecVW, unsigned int i, int64_t w){
    if(i==vecVW.size()){ return 0; }
    
    int64_t val=0;
    int64_t w_minusW = w - vecVW[i].w;
    if(w_minusW<0){
        val = dps(vecVW, i+1, w);
    }else{
        val = max(dps(vecVW, i+1, w_minusW)+vecVW[i].v, dps(vecVW, i+1, w));
    }
    return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<struct VW> vecVW(N);
    for(unsigned int i=0; i<vecVW.size(); ++i){ cin >> vecVW[i].v >> vecVW[i].w; }
    
    cout << dps(vecVW, 0, (int64_t)W) << endl;
    
    return 0;
}
