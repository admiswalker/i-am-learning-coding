// ref: https://img.atcoder.jp/abc115/editorial.pdf

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

int64 solver(int64 L, int64& curNum, int64 X){ // cur: current
    int64 numPate=0ll;
    if(curNum>=X){ return numPate; }
    if(L==0ll){
        ++curNum; ++numPate; // P
        return numPate;
    }
    
    ++curNum;                          if(curNum>=X){ return numPate; } // B
    numPate += solver(L-1, curNum, X); if(curNum>=X){ return numPate; } // L-1
    ++curNum; ++numPate;               if(curNum>=X){ return numPate; } // P
    numPate += solver(L-1, curNum, X); if(curNum>=X){ return numPate; } // L-1
    ++curNum;                          if(curNum>=X){ return numPate; } // B
    
    return numPate;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N, X; cin >> N >> X;
    
    int64 curNum=0ll;
    cout << solver(N, curNum, X) << endl;
    
    return 0;
}
// 2160549382716056
// 

