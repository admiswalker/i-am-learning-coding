#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

uint sieve(const uint n){
    uint p=0;
    vector<bool> pTable(n+1, true); pTable[0]=pTable[1]=false;
    for(uint ti=2; ti<=n; ++ti){
        if(!pTable[ti]){ continue; }
        p++;
        for(uint i=2*ti; i<=n; i+=ti){ pTable[i]=false; }
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint n; cin >> n; --n;
    cout << sieve(n) << endl;
    
    return 0;
}
