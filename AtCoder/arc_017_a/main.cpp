#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

bool isPrime(uint n){
    for(uint i=2; i<=sqrt(n); ++i){
        if(n%i==0){ return false; }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    cout << (isPrime(N) ? "YES" : "NO") << endl;
    
    return 0;
}
