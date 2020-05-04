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

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    
    int l=0;
    int r=vA.size(); // index
    while(r-l>1){
        int c = (l+r)/2;
        int64 l_gcd = gcd_range(vA, l, c);
        int64 r_gcd = gcd_range(vA, c, r);
        if(l_gcd<r_gcd){ l=c;
        }     else     { l=r; }
    }
    
    // gcd without l
    int64 gcd_wo_l = l!=0 ? vA[0]:vA[1];
    for(int i=1; i<N; ++i){
        if(i==l){ continue; }
        gcd_wo_l = gcd(gcd_wo_l, vA[i]);
    }
    
    // gcd without r
    int64 gcd_wo_r = r!=0 ? vA[0]:vA[1];
    for(int i=1; i<N; ++i){
        if(i==r){ continue; }
        gcd_wo_r = gcd(gcd_wo_r, vA[i]);
    }
    
    cout << ( gcd_wo_l<gcd_wo_r ? gcd_wo_l:gcd_wo_r ) << endl;
    
    return 0;
}
