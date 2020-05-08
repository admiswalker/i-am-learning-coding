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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W; cin >> H >> W;
    vector<string> m(H); for(int h=0; h<H; ++h){ cin >> m[h]; } // matrix
    
    // LR: Is continue more than 2 ?
    for(int h=0; h<H; ++h){
        for(int w=1; w<W; ++w){
            if( (m[h][w-1]=='#' || m[h][w-1]=='O') &&
                (m[h][w  ]=='#' || m[h][w  ]=='O')    )
            {
                m[h][w-1] = 'O';
                m[h][w  ] = 'O';
            }
        }
    }
    
    // TB: Is continue more than 2 ?
    for(int w=0; w<W; ++w){
        for(int h=1; h<H; ++h){
            if( (m[h-1][w]=='#' || m[h-1][w]=='O') &&
                (m[h  ][w]=='#' || m[h  ][w]=='O')    )
            {
                m[h-1][w] = 'O';
                m[h  ][w] = 'O';
            }
        }
    }
    
    // Is there '#' ?
    bool TF=true;
    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            if( m[h][w] == '#' ){ TF=false; }
        }
    }
    cout << (TF ? "Yes":"No") << endl;
    
    return 0;
}
