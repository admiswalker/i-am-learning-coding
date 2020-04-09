// ref: https://drken1215.hatenablog.com/entry/2019/03/21/234900

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    
    vector<int> vP(M), vY(M);
    vector<vector<int>> vvPY(N);
    for(uint i=0; i<M; ++i){
        int p, y; cin >> p >> y; --p;
        vP[i] = p;
        vY[i] = y;
        vvPY[p].push_back(y);
    }
    
    for(uint pi=0; pi<vvPY.size(); ++pi){
        sort(vvPY[pi].begin(), vvPY[pi].end());
        
        vvPY[pi].erase( unique(vvPY[pi].begin(), vvPY[pi].end()), vvPY[pi].end() );
    }
    
    for(uint i=0; i<M; ++i){
        int pi = vP[i];
        int idx = lower_bound(vvPY[pi].begin(), vvPY[pi].end(), vY[i]) - vvPY[pi].begin();
        printf("%06d%06d\n", pi+1, idx+1);
    }
    
    return 0;
}
