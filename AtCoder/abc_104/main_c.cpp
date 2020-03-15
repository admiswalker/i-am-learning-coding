// ref: https://img.atcoder.jp/abc104/editorial.pdf
// ref: https://atcoder.jp/contests/abc104/submissions/2954675

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint D, G; cin >> D >> G;
    vector<int> vP(D), vC(D);
    for(uint i=0; i<D; ++i){
        cin >> vP[i] >> vC[i];
    }
    
    int ans=INT_MAX;
    for(uint d=0; d<((uint)1<<D); ++d){
        int64 sum=0ll;
        int rest_max=D-1;
        int num=0;
        
        for(uint i=0, dTmp=d; i<D; ++i, dTmp>>=1){
            if(dTmp&1){ rest_max=i; continue; }
            sum += 100*(i+1)*vP[i] + vC[i];
            num += vP[i];
        }
        if(sum<G){
            int64 restSize = 100 * (rest_max+1);
//            int64 need = ceil(((double)G - (double)sum)/(double)restSize);
            int64 need = (G - sum + restSize - 1)/restSize;
            if(need>=vP[rest_max]){ continue; }
            num += need;
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
    
    return 0;
}
