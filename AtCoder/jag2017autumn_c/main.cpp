#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

pair<vector<bool>, vector<uint>> sieve(const uint n){
    const uint n_p1 = n+1;
    vector<bool> pTable(n_p1, true); pTable[0]=false; pTable[1]=false;
    vector<uint> vPrime;
    for(uint ti=2; ti<n_p1; ++ti){
        if(!pTable[ti]){ continue; }
        vPrime.push_back( ti );
        for(uint i=ti*2; i<n_p1; i+=ti){ pTable[i]=false; }
    }
    return {pTable, vPrime};
}

struct fact{
    uint prime;
    uint num;
};
vector<fact> factor(const vector<uint>& vPrime, uint n){
    vector<fact> vFactor;
    uint n_prev = n;
    for(uint pi=0; pi<vPrime.size(); ++pi){
        uint p=0;
        for(uint i=0;; ++i){
            if(n%vPrime[pi]!=0){ break; }
            n /= vPrime[pi];
            ++p;
        }
        if(p!=0){
            vFactor.push_back( {vPrime[pi], p} );
        }
        if(n==1){ break; }
    }
    if(n==n_prev){
        vFactor.push_back( {n, 1} );
    }
    return vFactor; 
}
uint sum(const vector<fact>& vFact){
    uint n=0;
    for(uint i=0; i<vFact.size(); ++i){
        n += vFact[i].num;
    }
    return n;
}

bool isPrime(const vector<bool>& pTable, uint n){
    if(n>pTable.size()){ return false; }
    return pTable[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint l, r; cin >> l >> r;
    vector<bool> pTable; vector<uint> vPrime;
    tie(pTable, vPrime) = sieve( sqrt(r) );
    
    uint ans=0;
    for(uint i=l; i<=r; ++i){
        vector<fact> vFact = factor(vPrime, i);
        if(isPrime(pTable, sum(vFact) )){ ++ans; }
    }
    cout << ans << endl;
    
    return 0;
}
