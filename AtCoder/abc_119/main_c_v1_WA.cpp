// ref: https://www.dropbox.com/sh/arnpe0ef5wds8cv/AABP7ueaiQAVNZLQn4NjGZBSa/ABC119/C/in?dl=0&preview=b04&subfolder_nav_tracking=1

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

vector<int> gen_allLen(vector<int>& vBit, const vector<int>& vL, const int& bit_used){
    vector<int> vL_all;
    vBit.resize( 0 );
    for(int bit=1; bit < 1<<vL.size(); ++bit){
        int len=0;
        for(uint vi=0; vi<vL.size(); ++vi){
            if( bit_used & (1<<vi) ){ continue; }
            if( bit      & (1<<vi) ){ len += vL[vi]; }
        }
        if(len==0){ continue; }
        vL_all.push_back( len );
        vBit.push_back( bit );
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
    
    vector<vector<int>> vvABC = {{A, B, C}, {A, C, B}, {B, A, C}, {B, C, A}, {C, A, B}, {C, B, A}}; 
    
    int mp_min=INT_MAX;
    for(uint i=0; i<vvABC.size(); ++i){
        int mp_sum  =0;
        int bit_used=0;
        for(uint j=0; j<vvABC[i].size(); ++j){
            int ABC = vvABC[i][j];
            printn(ABC);
            
            vector<int> vBit;
            vector<int> vL_all  = gen_allLen(vBit, vL, bit_used); if( vL_all.size()==0 ){ mp_sum=INT_MAX; break; }
            vector<int> vL_diff = vec_abs_diff(ABC, vL_all);
            int idx = min_element(vL_diff.begin(), vL_diff.end()) - vL_diff.begin();
            mp_sum += vL_diff[ idx ] + 10*(__builtin_popcount( vBit[ idx ] ) - 1);
            bit_used |= vBit[ idx ];
            
            printn(vL_all );
            printn(vL_diff);
            printn(idx);
            printn(vL_diff[idx]);
            printn(vBit[idx]);
            printn(__builtin_popcount( vBit[ idx ] ));
            printn( vL_diff[ idx ] + 10*(__builtin_popcount( vBit[ idx ] ) - 1) );
            printn(mp_sum);
            printf("\n");
        }
        printn(mp_min);
        
        mp_min = min(mp_min, mp_sum);
        printf("----\n");
        printf("\n");
    }
    cout << mp_min << endl;
    
    return 0;
}
