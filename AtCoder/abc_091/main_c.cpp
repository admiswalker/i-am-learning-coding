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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N; cin >> N;
    vector<pair<int,int>> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i].first >> vA[i].second; } sort(vA.begin(), vA.end());
    vector<pair<int,int>> vB(N); for(int i=0; i<N; ++i){ cin >> vB[i].first >> vB[i].second; } sort(vB.begin(), vB.end());
    
    int cnt = 0;
    for(int ib=0; ib<N; ++ib){
        for(int ia=0; ia<N; ++ia){
            if(! (vA[ia].first<vB[ib].first && vA[ia].second<vB[ib].second) ){ continue; }
            ++cnt;
            vA[ia].first  = INT_MAX;
            vA[ia].second = INT_MAX;
            break;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
