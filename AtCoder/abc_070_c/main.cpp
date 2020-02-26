#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint64 gcd(uint64 a, uint64 b){ // greatest common divisor
    if(b==0){ return a; }
    return gcd(b, a%b);
}
uint64 lcm(uint64 a, uint64 b){ // least common multiple
    return a / gcd(a, b) * b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<uint64> vT(N);
    for(uint i=0; i<N; ++i){
        cin >> vT[i];
    }
    
    uint64 ret = 1ull;
    for(uint i=0; i<N; ++i){
        ret = lcm(ret, vT[i]);
    }
    cout << ret << endl;
    
    return 0;
}
