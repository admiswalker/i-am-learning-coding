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
    
    uint N, Q; cin >> N >> Q;
    string s; cin >> s;
    vector<int> vCnt(s.size()+1, 0);
    vector<int> vCS (s.size()+1, 0); // cumulative sum
    
    for(uint i=1; i<s.size(); ++i){
        if(s[i-1]=='A' && s[i]=='C'){ vCnt[i+1] = 1; }
    }
    
    vCS[0] = vCnt[0];
    for(uint i=1; i<vCS.size(); ++i){
        vCS[i] = vCS[i-1] + vCnt[i];
    }
    
    for(uint i=0; i<Q; ++i){
        uint l, r; cin >> l >> r;
        if(s[l-1]=='C'){ ++l; }
        cout << vCS[r] - vCS[l-1] << endl;
    }
    
    return 0;
}
/*
ACACTACG
3 7
2 3
1 8
           A C A C T A C G
vCnt = [ 0 0 1 0 1 0 0 1 0 ]
vCS  = [ 0 0 1 1 2 2 2 3 3 ]
*/
