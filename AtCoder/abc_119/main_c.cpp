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

vector<int> gen_allLen(vector<int>& vVi, const vector<int>& vL, const int& vL_used){
    vector<int> vL_all;
    vVi.resize( 0 );
    for(int vi=1; vi < 1<<vL.size(); ++vi){
        int len=0;
        for(uint i=0; i<vL.size(); ++i){
            if( vL_used & (1<<i) ){ continue; }
            if( vi      & (1<<i) ){ len += vL[vi]; }
        }
        vL_all.push_back( len );
        vVi.push_back( vi );
    }
    return vL_all;
}

vector<int> vec_abs_diff(int ABC, vector<int>& vL_all){
    for(uint i=0; i<vL_all.size(); ++i){
        vL_all[i] = abs( vL_all[i] - ABC );
    }
    return vL_all;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N; int A, B, C; cin >> N >> A >> B >> C;
    vector<int> vL(N);
    for(uint i=0; i<N; ++i){ cin>>vL[i]; }
    
    vector<vector<int>> vvOrder = {{A, B, C}, {A, C, B}, {B, A, C}, {B, C, A}, {C, A, B}, {C, B, A}};
    
    int mp_min;
    for(uint i=0; i<vvOrder.size(); ++i){
        int mp_sum;
        int vL_used;
        for(uint j=0; j<vvOrder[i].size(); ++j){
            vector<int> vL_all;
            vector<int> vVi;
            vL_all = gen_allLen(vVi, vL, vL_used);
            vL_all = vec_abs_diff(vvOrder[i][j], vL_all);
            int idx = min_element(vL_all.begin(), vL_all.end()) - vL_all.begin();
            mp_sum += vL_all[ idx ];
            vL_used |= vVi[ idx ];
        }
        mp_min = min(mp_min, mp_sum);
    }
    cout << mp_min << endl;
    
    return 0;
}
