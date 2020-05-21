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
    
    int H, W, D; cin >> H >> W >> D;
    vector<pair<int,int>> idx2ij(H*W);
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            int idx; cin >> idx; --idx;
            idx2ij[ idx ].first  = i;
            idx2ij[ idx ].second = j;
        }
    }
    
    int Q; cin >> Q;
    for(int i=0; i<Q; ++i){
        int L, R; cin >> L >> R; --L; --R;
        
        int sum = 0;
        int idx = L;
        while(idx!=R){
            int i = idx2ij[ idx ].first;
            int j = idx2ij[ idx ].second;
            idx += D;
            int x = idx2ij[ idx ].first;
            int y = idx2ij[ idx ].second;
            sum += abs( x-i ) + abs( y-j );
        }
        
        cout << sum << endl;
    }
    
    return 0;
}
