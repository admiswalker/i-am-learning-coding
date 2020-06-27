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
    
    int N; cin >> N;
    vector<int> v_fBits(N, 0);
    for(int n=0; n<N; ++n){
        for(int i=0; i<10; ++i){
            v_fBits[n] <<= 1;
            
            int f; cin >> f;
            if(f==1){ v_fBits[n] += 1; }
        }
    }
    
    vector<vector<int>> vvP(N, vector<int>(11));
    for(int r=0; r<N; ++r){
        for(int c=0; c<11; ++c){
            cin >> vvP[r][c];
        }
    }
    
    int sum=INT_MIN;
    for(int sBits=0; sBits < (1<<10); ++sBits){
        if(__builtin_popcount( sBits ) == 0){ continue; }
        
        int sum_tmp=0ll;
        for(int i=0; i<N; ++i){
            int num = __builtin_popcount( v_fBits[i] & sBits );
            sum_tmp += vvP[i][num];
        }
        
        sum = max(sum, sum_tmp);
    }
    
    cout << sum << endl;
    
    return 0;
}
