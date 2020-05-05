// ref: https://img.atcoder.jp/abc125/editorial.pdf

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

int64 abs_sum(const vector<int>& v){
    int64 ret=abs(v[0]);
    for(uint i=1; i<v.size(); ++i){ ret+=abs(v[i]); }
    return ret;
}
int64 min(int64 lhs, int64 rhs){ return (lhs<rhs ? lhs:rhs); }
int64 abs_min(const vector<int>& v){
    int64 ret=abs(v[0]);
    for(uint i=1; i<v.size(); ++i){ ret=min(ret, abs(v[i])); }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vA(N); for(uint i=0; i<N; ++i){ cin >> vA[i]; }
    
    int64 s = abs_sum(vA);
    int64 m = abs_min(vA);
    int64 minusNum = count_if(vA.begin(), vA.end(), [](int x){return x<0;} );
    
    cout << (minusNum&1 ? (s-2*m):s) << endl;
    
    return 0;
}
