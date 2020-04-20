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
    
    uint64 N, K; cin >> N >> K;
    vector<int64> vA(N);
    for(uint i=0; i<N; ++i){ cin >> vA[i]; }
    
    // count num 0 1
    uint64 max = 0ull;
    int numShift = 64 - __builtin_clzll(K) - 1;
    for(uint64 digit_i=1ull<<numShift; digit_i!=0ull; digit_i>>=1){
        uint64 num0 = 0ull;
        uint64 num1 = 0ull;
        for(uint i=0; i<N; ++i){
            if(digit_i & vA[i]){ ++num1;
            }       else       { ++num0; }
        }
        max <<= 1;
        if(num1 <= num0){ max += 1ll; }
    }
    uint64 X = K & max;
    
    uint64 sum=0ull;
    for(uint i=0; i<N; ++i){
        sum += X ^ vA[i];
    }
    cout << sum << endl;
    
    return 0;
}
