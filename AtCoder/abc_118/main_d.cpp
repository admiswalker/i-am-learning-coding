// ref: https://competitive-kivantium.hateblo.jp/entry/2019/02/17/000439
// ref: https://img.atcoder.jp/abc118/editorial.pdf

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

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> vA(M); for(int i=0; i<M; ++i){ cin>>vA[i]; }
    
    vector<char> val2char = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> val2num = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    vector<string> dp((N+1)*M);
    
    for(int ni=0; ni<=N; ++ni){
        for(int i=0; i<M; ++i){
            int numA = val2num[ vA[i] ];
            if(numA > ni){ continue; }
            
            string tmp;
            if      ( ni == numA            ){ tmp += val2char[ vA[i] ];
            }else if( dp[ni-numA].size()!=0 ){ tmp += val2char[ vA[i] ] + dp[ni-numA];
            }else                            { continue; }
            
            if(  tmp.size() > dp[ni].size() ||
               ( tmp.size()==dp[ni].size() && tmp>dp[ni] ) ){
                dp[ni] = tmp;
            }
        }
    }
    cout << dp[N] << endl;
    
    return 0;
}
