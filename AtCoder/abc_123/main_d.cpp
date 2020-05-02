// ref: https://img.atcoder.jp/abc123/editorial.pdf

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

int64 next(const vector<int64>& v, uint idx){
    return (idx<v.size() ? v[idx] : v[v.size()-1] );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<int64> vA(X); for(uint i=0; i<X; ++i){ cin >> vA[i]; } sort(vA.begin(), vA.end(), greater<int64>());
    vector<int64> vB(Y); for(uint i=0; i<Y; ++i){ cin >> vB[i]; } sort(vB.begin(), vB.end(), greater<int64>());
    vector<int64> vC(Z); for(uint i=0; i<Z; ++i){ cin >> vC[i]; } sort(vC.begin(), vC.end(), greater<int64>());
    
    vector<int64> vK(K);
    for(uint x=0; x<X; ++x){
        for(uint y=0; y<Y; ++y){
            for(uint z=0; z<Z; ++z){
                if((x+1)*(y+1)*(z+1)>K){ continue; }
                vK.push_back( vA[x]+vB[y]+vC[z] );
            }
        }
    }
    
    sort(vK.begin(), vK.end(), greater<int64>());
    for(uint i=0; i<K; ++i){ cout << vK[i] << endl; }
    
    return 0;
}
