// ref: https://www.slideshare.net/chokudai/union-find-49066733?ref=https://atcoder.jp/contests/atc001/tasks/unionfind_a

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

class unionFind{
private:
    vector<uint> par; // parent
public:
    unionFind(uint rhs){
        par.resize(rhs);
        for(uint i=0; i<par.size(); ++i){ par[i]=i; }
    }
    ~unionFind(){}
    
    uint root(uint rhs){ // returning the root index.
        if(rhs==par[rhs]){ return rhs;
        }      else      { return par[rhs]=root(par[rhs]); }
    }
    
    bool unite(uint lhs, uint rhs){
        uint rL = root(lhs);
        uint rR = root(rhs);
        if(par[rL]==par[rR]){ return false; }
        
        par[rL] = rR;
        return true;
    }
    
    bool same(uint lhs, uint rhs){
        return root(par[lhs])==root(par[rhs]);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, Q;
    cin >> N >> Q;
    class unionFind uf(N);
    
    for(uint i=0; i<Q; ++i){
        uint P, A, B; cin >> P >> A >> B;
        if(P==0){ uf.unite(A, B);
        }  else { cout << (uf.same(A, B)?"Yes":"No") << endl; }
    }
    
    return 0;
}
