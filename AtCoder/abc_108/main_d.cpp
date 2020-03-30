// ref: https://drken1215.hatenablog.com/entry/2018/09/02/020500

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
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int L; cin >> L;
    
    int N=0, pow2n=1; while(pow2n<=L){ pow2n*=2; ++N; } // max(N) taht satisfies 2^n <=L.
    int M = (N-1)*2 + popcount(L)-1;
    cout << N << ' ' << M << endl;
    
    // filling [0, 2^n]
    for(uint i=0; i<N; ++i){
        cout << (i+1) << ' ' << (i+2) << ' ' <<   0    << endl;
        cout << (i+1) << ' ' << (i+2) << ' ' << (1<<i) << endl;
    }
    
    // filling (2^n, L]
    int sum = 1<<(N-1);
    int cur = 1<<(N-2);
    for(uint i=N-2; i>=0; --i){
        if(L & cur){
            cout << i+1 << ' ' << N << ' ' << sum << endl;
            sum += cur;
        }
        cur>>=1;
    }
    
    int cur = 1<<(N-1);
    for(uint i=N-2; i>=0; --i){
        if(L & (1<<i)){
            ;
        }
    }
    
    int restL = L - 1<<(N-1); // restL = L - 2^N = L - 1<<(N-1)
    int n=N-1;
    while(restL!=0){
        restL;
        int N=0, pow2n=1; while(pow2n<=restL){ pow2n*=2; ++N; } // max(N) taht satisfies 2^n <=L.
        
        if(){}
        ;
    }
    
    int l = L;
    for(uint i=0; i<N; ++i){
        if(l<=0){ break; }
        if(l & 1){
            ret*b;
            cout <<  << endl;
        }
        l *= l;
        l >>= 1;
    }
    for(uint i=0; i<; ++i){
        if(){ ; }
    }
    
    return 0;
}
