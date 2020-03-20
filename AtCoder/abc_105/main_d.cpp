// ref: https://img.atcoder.jp/abc105/editorial.pdf
// ref: http://osishow3.hateblo.jp/entry/2017/04/03/235027

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int pow2(uint e){
    int p=1;
    for(uint i=0; i<e; ++i){ p*=2; }
    return p;
}
int nCr(int n, int r){
    int ret=1;
    for(int i=0; i<r; ++i){
        ret = ret * (n-i) / (i+1);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    vector<uint> vA(N);
    for(uint i=0; i<N; ++i){ cin >> vA[i]; }
    
    vector<uint64> vA_sum(N); vA_sum[0] = vA[0];
    for(uint i=1; i<N; ++i){
        vA_sum[i] = vA[i] + vA_sum[i-1];
    }
    
    unordered_map<int, int> hashT;
    for(uint i=0; i<N; ++i){
        int mod = vA_sum[i] % M;
        
        auto itr = hashT.find( mod );
        if(itr!=hashT.end()){ ++(itr->second);
        }       else        { hashT.insert( {mod, 1} );
        }
    }
    
    int ans=0;
    for(auto itr=hashT.begin(); itr!=hashT.end(); ++itr){
        if(itr->first!=0 && itr->second<2){ continue; }
        
        if(itr->first==0){ ans += nCr(itr->second, 2) + itr->second;
        }      else      { ans += nCr(itr->second, 2);
        }
    }
    cout << ans << endl;
    
    return 0;
}
