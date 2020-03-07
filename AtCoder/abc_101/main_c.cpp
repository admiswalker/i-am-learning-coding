#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, K; cin >> N >> K;
    
    uint idx;
    for(uint i=1; i<=N; ++i){
        uint num; cin >> num;
        if(num==1){ idx=i; }
    }
    
    double n_before = ceil((double)(idx-1)/(double)(K-1));
    double n_after  = ceil((double)(N-idx)/(double)(K-1));
    cout << (int)(n_before+n_after) << endl;
    
    return 0;
}
