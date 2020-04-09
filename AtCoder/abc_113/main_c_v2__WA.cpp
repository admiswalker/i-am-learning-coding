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
    vector<int> vP(M);
    vector<int> vY(M);
    vector<vector<int>> vvPY(N);
    for(uint i=0; i<M; ++i){
        int P, Y; cin >> P >> Y;
        vP[i] = P;
        vY[i] = Y;
        vvPY[P-1].push_back( Y );
    }
    for(uint i=0; i<vvPY.size(); ++i){
        sort(vvPY[i].begin(), vvPY[i].end());
    }
    
    unordered_map<int64, int64> ht;
    for(uint pi=0; pi<vvPY.size(); ++pi){
        for(uint yi=0; yi<vvPY[pi].size(); ++yi){
            int P = pi+1;
            int Y = vvPY[pi][yi];
            int64 key = 1000000ll*(int64)P + (int64)Y;      // input
            int64 val = 1000000ll*(int64)P + (int64)yi+1ll; // output
            ht[key] = val;
        }
    }
    
    for(uint i=0; i<M; ++i){
        int P = vP[i];
        int Y = vY[i];
        int64 key = 1000000ll*(int64)P + (int64)Y;
        printf("%012ld\n", (int64)ht[key]);
    }
    
    return 0;
}
