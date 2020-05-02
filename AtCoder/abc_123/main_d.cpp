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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<int64> vA(X); for(uint i=0; i<X; ++i){ cin >> vA[i]; } sort(vA.begin(), vA.end(), greater<int>());
    vector<int64> vB(Y); for(uint i=0; i<Y; ++i){ cin >> vB[i]; } sort(vB.begin(), vB.end(), greater<int>());
    vector<int64> vC(Z); for(uint i=0; i<Z; ++i){ cin >> vC[i]; } sort(vC.begin(), vC.end(), greater<int>());
    
    uint ia=0;
    uint ib=0;
    uint ic=0;
    for(uint i=0; i<K; ++i){
        cout << vA[ia] + vB[ib] + vC[ic] << endl;
        
        if      (ia+1<vA.size()&& next(vA,ia+1)>=next(vB,ib+1) && next(vA,ia+1)>=next(vC,ic+1)){ ++ia;
        }else if(ib+1<vB.size()&& next(vB,ib+1)>=next(vA,ia+1) && next(vB,ib+1)>=next(vC,ic+1)){ ++ib;
        }else if(ic+1<vC.size()&& next(vC,ic+1)>=next(vA,ia+1) && next(vC,ic+1)>=next(vB,ib+1)){ ++ic; }
    }
    
    return 0;
}
