#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint countPrime2(uint rhs){
    if(rhs==0){ return 0; }
    uint sum=0;
    while(!(rhs&1)){
        ++sum;
        rhs >>= 1;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint64 sum=0ull;
    uint N; cin >> N;
    for(uint i=0; i<N; ++i){
        uint a; cin >> a;
        sum += countPrime2(a);
    }
    cout << sum << endl;
    
    return 0;
}
