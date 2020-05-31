// ref: https://img.atcoder.jp/abc084/editorial.pdf

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int N=100000;
    
    int Q; cin >> Q;
    
    vector<bool> pTbl(N+1, true);
    pTbl[0] = false;
    pTbl[1] = false;
    for(int prime=2; prime<=N; ++prime){
        if(!pTbl[prime]){ continue; }
        for(int tmp=2*prime; tmp<=N; tmp+=prime){ pTbl[tmp]=false; }
    }
    
    vector<int> vSimilar2017;
    for(int i=0; i<=N; ++i){
        if(pTbl[i] && pTbl[(i+1)/2]){
            vSimilar2017.push_back(i);
        }
    }
    
    vector<int> cSum(N+1, 0);
    for(uint i=0; i<vSimilar2017.size(); ++i){
        ++cSum[ vSimilar2017[i] ];
    }
    for(int i=1; i<=N; ++i){ cSum[i] += cSum[i-1]; }
    
    for(int i=0; i<Q; ++i){
        int l, r; cin >> l >> r;
        cout << (cSum[r] - cSum[l-1]) << endl;
    }
    
    return 0;
}
