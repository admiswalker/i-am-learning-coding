#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;
typedef __uint128_t uint128;

uint128 gcd(uint128 a, uint128 b){ // greatest common divisor
    if(b==0){ return a; }
    return gcd(b, a%b);
}
uint128 lcd(uint128 a, uint128 b){ // least common multiple
    return (a*b) / gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<uint64> vT(N);
    for(uint i=0; i<N; ++i){
        cin >> vT[i];
    }
    
    uint64 ret = lcd(vT[0], vT[1]);
    for(uint i=2; i<N; ++i){
        ret = lcd(ret, vT[i]);
    }
    cout << ret << endl;
    
    return 0;
}
