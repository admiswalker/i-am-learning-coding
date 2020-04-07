#define _GLIBCXX_DEBUG
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

vector<pair<int,int>> factor(int M){
    vector<pair<int,int>> vNP;
    for(int div=2; div*div<=M; ++div){
        if(M%div!=0){ continue; }
        
        int num=1; M/=div; while(M%div!=0){ M/=div; ++num; }
        vNP.push_back( pair<int,int>(div, num) );
    }
    return vNP;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    if(M%N==0){ cout << M/N << endl; return 0; }
    
    vector<pair<int,int>> vNP = factor(M);
    for(uint i=vNP.size()-1; i>=0; ++i){
        if(M/vNP[i].first >= N){ cout << vNP[i].first << endl; return 0; }
    }
    cout << 1 << endl;
    
    return 0;
}
