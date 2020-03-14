// ref: https://img.atcoder.jp/abc103/editorial.pdf

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vA(N);
    for(uint i=0; i<N; ++i){ cin>>vA[i]; }
    
    int64 sum=0ll;
    for(uint i=0; i<N; ++i){
        sum += vA[i] - 1;
    }
    cout << sum << endl;
    
    return 0;
}
