// ref: https://drken1215.hatenablog.com/entry/2019/04/27/224100_1

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

int64 gcd(int64 a, int64 b){
    if(b==0){ return a; }
    return gcd(b, a%b);
}

int64 gcd_range(vector<int> vA, int l, int r){
    int64 ret=vA[l];
    for(int i=l+1; i<r; ++i){
        ret = gcd(vA[i], ret);
    }
    return ret;
}

int64 max(int64 l, int64 r){ return (r>=l ? r:l); }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    
    vector<int> vL(N+1, 0); for(int i=0; i< N; ++i){ vL[i+1] = gcd(vL[i], vA[i  ]); }
    vector<int> vR(N+1, 0); for(int i=N; i>=1; --i){ vR[i-1] = gcd(vR[i], vA[i-1]); }
    
    int ret = 0;
    for(int i=0; i<N; ++i){
        ret = max(ret, gcd(vL[i], vR[i+1]));
    }
    
    cout << ret << endl;
    
    return 0;
}
