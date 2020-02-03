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
    unionFind(){}
    unionFind(uint rhs){
        par.resize(rhs);
        for(uint i=0; i<par.size(); ++i){ par[i]=i; }
    }
    ~unionFind(){}
    
    uint root(uint rhs){
        if(par[rhs]==rhs){ return rhs;
        }      else      { par[rhs]=root(par[rhs]); return par[rhs]; }
    }
    
    void unite(uint rhs, uint lhs){
        uint rR = root(rhs);
        uint rL = root(lhs);
        if(par[rR]==par[rL]){ return; }
        
        par[rR] = rL;
    }

    bool same(uint rhs, uint lhs){
        return root(par[rhs])==root(par[lhs]);
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
