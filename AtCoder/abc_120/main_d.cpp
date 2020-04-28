// ref: https://drken1215.hatenablog.com/entry/2019/03/03/224600

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

using namespace std;

//---

template <typename T>
inline void print(const T& rhs){ std::cout<<" = "<<rhs<<std::endl; }
template <typename T>
inline void print(const std::vector<T>& rhs){
    std::cout<<" = [ ";
    for(uint i=0; i<rhs.size(); ++i){ std::cout<<rhs[i]<<' '; }
    std::cout<<"]"<<std::endl;
}
template <typename T>
inline void print(const std::vector<std::vector<T>>& rhs){
    std::cout<<" = "<<std::endl;
    std::cout<<"[[ ";
    for(uint p=0; p<rhs.size(); ++p){
        if(p!=0){ std::cout<<" [ "; }
        for(uint q=0; q<rhs[p].size(); ++q){
            std::cout<<rhs[p][q]<<' ';
        }
        if(p!=rhs.size()-1){ std::cout<<"]"<<std::endl; }
    }
    std::cout<<"]]"<<std::endl;
}
template <typename TL, typename TR>
inline void print(const std::vector<std::pair<TR,TL>>& rhs){
    std::cout<<" = [";
    uint i=0;
    for(; i<rhs.size()-1; ++i){ std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"], "; }
    std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"]]" << endl;
}
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

class unionFind_size{
 private:
    vector<int> par; // parent
 public:
    unionFind_size(uint size): par(size, -1) {}
    ~unionFind_size(){}
    
    int root(int rhs){
        if( par[rhs] < 0 ){ return rhs;
        }       else      { return par[rhs] = root(par[rhs]); }
    }
    
    bool unite(int lhs, int rhs){
        int rL = root(lhs);
        int rR = root(rhs);
        if(rL==rR){ return false; }
//        if(par[rL]>par[rR]){ swap(rL, rR); }
        par[rL] += par[rR];
        par[rR] = rL;
        return true;
    }
    
    bool same(int lhs, int rhs){
        return root(lhs)==root(rhs);
    }
    
    int size(int rhs){
        return -par[root(rhs)];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64 N, M; cin >> N >> M;
    vector<int> vA(M), vB(M);
    for(int i=M-1; i>=0; --i){ cin >> vA[i] >> vB[i]; --vA[i]; --vB[i]; }
    
    unionFind_size uf(N);
    vector<int64> vAns(M);
    int64 cur = N*(N-1)/2;
    for(int i=0; i<M; ++i){
        vAns[i] = cur;
        
        if(uf.same(vA[i], vB[i])){ continue; }
        
        int a = uf.size(vA[i]);
        int b = uf.size(vB[i]);
        cur -= a * b;
        
        uf.unite(vA[i], vB[i]);
    }
    
    for(int i=M-1; i>=0; --i){ cout << vAns[i] << endl; }
    return 0;
}
