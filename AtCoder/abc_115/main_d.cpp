// ref: https://img.atcoder.jp/abc115/editorial.pdf
// ref: https://drken1215.hatenablog.com/entry/2019/05/13/114600

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

/*
int64 solver(int64 L, int64& curNum, int64 X){ // cur: current
    int64 numPate=0ll;
    if(curNum>=X){ return numPate; }
    if(L==0ll){
        ++curNum; ++numPate; // P
        return numPate;
    }
    
    ++curNum;            if(curNum>=X){ return numPate; } // B
    int64 buf = solver(L-1, curNum, X);
    numPate += buf;      if(curNum>=X){ return numPate; } // L-1
    ++curNum; ++numPate; if(curNum>=X){ return numPate; } // P
    numPate += buf;      if(curNum>=X){ return numPate; } // L-1
    ++curNum;            if(curNum>=X){ return numPate; } // B
    
    return numPate;
}

int main(){
    int N; int64 X; cin >> N >> X;
    
    int64 curNum=0ll;
    cout << solver(N, curNum, X) << endl;
    
    return 0;
}
//*/

//*
int64 pow2(int n){ return (1ll << (n-1)); }

int64 rec(int n, int64 x){
    if(n==0){ return (x<=0 ? 0:1); }
    
    int64 len     = pow2(n+2) - 3;
    int64 numPate = pow2(n+1) - 1;
    
    if(x<=len+1){ return rec(n-1, x-1);
    }    else   { return numPate + 1 + rec(n-1, x-1-(len+1)); }
}

int main(){
    int N; int64 X; cin >> N >> X;
    cout << rec(N, X) << endl;
    
    return 0;
}
//*/

